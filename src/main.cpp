#include "../include/window/window.hpp"
#include <fstream>
#include <iostream>


void initMangas() {


    std::filesystem::path path(re::constants::MANGA_DIR);
    
    if (!std::filesystem::exists(path)) {
        std::cout << "INVALID MANGA FOLDER -> " << re::constants::MANGA_DIR << '\n';
        std::exit(-1);
    }


    if (!std::filesystem::exists(std::filesystem::path(re::constants::MANGA_COVER_DIR))) {
        std::cout << "INVALID MANGA COVER FOLDER -> " << re::constants::MANGA_DIR << '\n';
        std::exit(-1);
    }

    // load mangas
    for (const auto& p : std::filesystem::directory_iterator(path)) {
        const std::filesystem::path& _path = p.path();
        re::globals::mangaByName.insert(
            {
                _path.stem().string(), 
                new re::Manga(_path)                
            }
        );
    }

    // load manga favorite and last chapter readed infos
    std::fstream file;
    std::string line;
    file.open(re::constants::MANGA_INFO_FILE, std::fstream::in);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::vector<std::string> v;
            re::split(line, '-', v);
            const std::string& mangaName = v.at(0);
            if (re::globals::mangaByName.find(mangaName) != re::globals::mangaByName.end()) {
                re::Manga* manga = re::globals::mangaByName.at(mangaName);
                manga->lastChapterReaded = std::stoi(v.at(1));
                manga->isFavorite = v.at(2) == "1";
            } else {
                std::cout << mangaName << " not founded!\n";
            }
        }
        file.close();
    }
}


void saveMangas() {
    std::fstream file;
    file.open(re::constants::MANGA_INFO_FILE, std::fstream::out);

    for (const auto& pair : re::globals::mangaByName) {
        file << pair.second->toString() << '\n';
        delete pair.second;
    }
    
    file.close();
}


void close() {
    saveMangas();
    re::ImagePool::rmvAll();
    re::Font::FontPool::rmvAll();
}


int main(void) {
    initMangas();
    re::Window w;
    w.run();
    close();
}