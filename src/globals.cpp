#include "../include/globals.hpp"


bool re::globals::screenHasFocus = false;


std::map<std::string, re::Manga*> re::globals::mangaByName;


std::string re::globals::currentManga = "";


sf::Vector2f re::globals::mousePos;


void re::globals::deleteManga(re::Manga* manga) {
    re::globals::mangaByName.erase(manga->name);
    std::filesystem::path p(manga->path);
    std::filesystem::remove_all(p);
}