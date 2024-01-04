#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "chapter.hpp"
#include "../constants.hpp"


namespace re {


    class Manga {

        public:
            const std::string path;
            const std::string name;
            const std::string coverImagePath;
            std::size_t lastChapterReaded;
            bool isFavorite;
            std::vector<re::Chapter*> chapters;
        
        public:
            Manga(const std::filesystem::path& _path);
            ~Manga();
            std::string toString() const;

    };
    
} // namespace re
