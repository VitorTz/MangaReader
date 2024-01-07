#pragma once
#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include "model/manga.hpp"
#include <SFML/Window/Keyboard.hpp>


namespace re {

    namespace globals {
        
        extern std::map<std::string, re::Manga*> mangaByName;
        extern std::string currentManga;
        extern sf::Vector2f mousePos;
        extern std::vector<sf::Keyboard::Key> pressedKeys;
        extern bool screenHasFocus;
        void deleteManga(re::Manga* manga);

    } // namespace globals
    

    
} // namespace re
