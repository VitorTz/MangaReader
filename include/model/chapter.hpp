#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include "../util/util.hpp"
#include "image.hpp"


namespace re {

    class Chapter {

        public:
            std::string path;
            std::string name;
            std::size_t num;
            std::vector<re::Image*> images;

        public:
            Chapter(const std::filesystem::path& _path);
            ~Chapter();
            void loadImages();
            void clearImages();

    };
    
} // namespace re
