#include "../include/globals.hpp"
#include <iostream>


std::map<std::string, re::Manga*> re::globals::mangaByName;


void re::globals::initGlobals() {
    
    for (const auto& p : std::filesystem::directory_iterator(re::MANGA_DIR)) {
        re::Manga* manga = new re::Manga(p.path());
        re::globals::mangaByName.insert({manga->name, manga});
    }

    std::ifstream file(re::MANGAS_SETTINGS.string());
    std::string line;
    if (file.is_open()) {
        std::vector<std::string> v;
        while (std::getline(file, line)) {
            re::split(line, '-', v);
            try {
                re::Manga* manga = re::globals::mangaByName.at(v[0]);
                manga->lastChapterReaded = std::stoi(v[1]);
                manga->isFavorite = (bool) std::stoi(v[2]);            
                v.clear();
            } catch (std::out_of_range& e ){
                std::cout << "Manga info not loaded " << line << '\n';
                std::exit(-1);
            }
        }
        file.close();
    }

}


void re::globals::deleteGlobals() {
    
    std::ofstream file(re::MANGAS_SETTINGS.string());
    if (file.is_open()) {
        for (const auto& pair : re::globals::mangaByName) {
            file << pair.first + '-' + std::to_string(pair.second->lastChapterReaded) + '-' + std::to_string((int) pair.second->isFavorite) + '\n';
        }
        file.close();
    }

    for (const auto& pair : re::globals::mangaByName) {
        delete pair.second;
    }

}