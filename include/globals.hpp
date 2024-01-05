#pragma once
#include <string>
#include <map>
#include "model/manga.hpp"
#include <SFML/System/Vector2.hpp>


namespace re {

    namespace globals {
        
        extern std::map<std::string, re::Manga*> mangaByName;
        extern std::string currentManga;
        extern sf::Vector2f mousePos;

    } // namespace globals
    

    
} // namespace re
