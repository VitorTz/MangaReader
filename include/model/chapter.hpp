#ifndef MANGA_READER_CHAPTER_HPP
#define MANGA_READER_CHAPTER_HPP
#include <filesystem>
#include <vector>
#include "image.hpp"
#include "../util/util.hpp"


namespace re {


    class Chapter {

        public:
            const std::filesystem::path path;
            const std::string name;
            const double num;
            std::vector<re::Image*> images;

        public:
            Chapter(const std::filesystem::path& path);
            ~Chapter();
            void loadImages();
            void clearImages();

    };

    
} // namespace re


#endif