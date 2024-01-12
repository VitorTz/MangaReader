#include "../include/manga_reader.hpp"


void init() {

    re::createDir(re::MANGA_PARENT_DIR);
    re::createDir(re::MANGA_DIR);
    re::createDir(re::MANGA_COVER_DIR);
    re::createDir(re::MANGA_SETTINGS_DIR);
    
    for (const std::filesystem::path& p : re::dirPaths(re::MANGA_DIR)) {
        re::globals::mangaMap.insert({p.stem(), std::make_shared<re::Manga>(p)});
    }

    // load favorite and last chapter readed
    std::ifstream f;
    f.open(re::MANGAS_SETTINGS_FILE, std::ifstream::in);
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line)) {
            re::MangaInfo mInfo = re::extractMangaInfo(line);
            if (!mInfo.success || !re::contains(re::globals::mangaMap, mInfo.name)) {
                std::cout << "Manga " << mInfo.name << " not founded\n";
                continue;
            }
            std::shared_ptr<re::Manga>& manga = re::globals::mangaMap.at(mInfo.name);
            manga->set(mInfo);
        }
        f.close();
    }
}


void close() {
    std::ofstream f;
    f.open(re::MANGAS_SETTINGS_FILE);
    if (f.is_open()) {
        for (auto& [name, manga] : re::globals::mangaMap) {
            f << name 
            << '-' 
            << std::to_string(manga->lastChapterReaded) 
            << '-' 
            << std::to_string(manga->isFavorite) 
            << '\n';
        }
        f.close();
    }
    re::TexturePool::rmvAll();
    re::FontPool::rmvAll();
}


int main() {
    init();
    re::Window w;
    w.run();
    close();
    return EXIT_SUCCESS;
}
