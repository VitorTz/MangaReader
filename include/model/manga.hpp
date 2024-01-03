#ifndef MANGA_READER_MANGA_INFO_HPP
#define MANGA_READER_MANGA_INFO_HPP
#include <filesystem>
#include <string>
#include <vector>
#include "chapter.hpp"


namespace re {


    class Manga {

        public:
            const std::filesystem::path path;
            const std::string name;
            std::size_t lastChapterReaded;
            std::vector<re::Chapter*> chapters;
            bool isFavorite;

        public:
            Manga(const std::filesystem::path& path); 
            ~Manga();

    };

    
} // namespace re



#endif