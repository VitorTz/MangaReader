#pragma once
#include <string>
#include <map>
#include "model/manga.hpp"


namespace re {

    namespace globals {
        
        extern std::map<std::string, re::Manga*> mangaByName;
        extern std::string currentManga;

    } // namespace globals
    

    
} // namespace re
