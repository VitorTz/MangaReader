#ifndef MANGA_READER_GLOBALS_HPP
#define MANGA_READER_GLOBALS_HPP
#include <string>
#include <map>
#include <fstream>
#include "model/manga.hpp"
#include "util/util.hpp"
#include "constants.hpp"


namespace re {

    namespace globals {

        extern std::map<std::string, re::Manga*> mangaByName;        

        void initGlobals();
        void deleteGlobals();
        
    } // namespace globals
    
    
} // namespace re


#endif