#ifndef MANGA_READER_GLOBALS_HPP
#define MANGA_READER_GLOBALS_HPP
#include <string>
#include <map>
#include "model/manga.hpp"


namespace re {

    namespace globals {

        extern std::map<std::string, re::Manga*> mangaByName;
        extern std::string currentMangaName;
        extern double currentTime;
        
    } // namespace globals
    
    
} // namespace re


#endif