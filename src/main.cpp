#include "../include/window/window.hpp"
#include "../include/globals.hpp"
#include <fstream>


void init() {
    std::filesystem::path settingsDir(re::MANGA_SETTINGS_DIR);
    std::filesystem::create_directory(settingsDir);
    
    std::filesystem::path mangaDirPath(re::MANGA_DIR);
    for (const auto& p : std::filesystem::directory_iterator(mangaDirPath)) {
        const std::filesystem::path& path = p.path();
        re::mangaMap.insert({path.stem(), std::make_shared<re::Manga>(path)});
    }

    std::ifstream f;
    f.open(re::MANGAS_SETTINGS_FILE, std::ifstream::in);
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            std::vector<std::string> v = re::split(line, '-');
            const std::string& mangaName = v.at(0);
            if (re::mangaMap.find(mangaName) != re::mangaMap.end()) {
                auto& manga = re::mangaMap.at(mangaName);
                manga->lastChapterReaded = std::stoi(v.at(1));
                manga->isFavorite = v.at(2) == "";
            } else {
                std::cout << "Manga " << mangaName << " not founded\n";
            }
        }
        f.close();
    }
}


void close() {
    std::ofstream f;
    f.open(re::MANGAS_SETTINGS_FILE);
    if (f.is_open()) {
        for (auto& [name, manga] : re::mangaMap) {
            f << name 
            << '-' 
            << std::to_string(manga->lastChapterReaded) 
            << '-' 
            << std::to_string(manga->isFavorite) 
            << '\n';
        }
        f.close();
    }
}


int main() {
    init();
    re::Window w;
    w.run();
    close();
    return 0;
}
