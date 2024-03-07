#pragma once
#include <cstddef>
#include <filesystem>
#include <vector>
#include <iostream>
#include <algorithm>
#include "../constants.hpp"


namespace mr {

    class Manga {

        public:
            std::filesystem::path path;
            std::string name;
            std::vector<std::filesystem::path> chapters;
            std::size_t last_readed_chapter = 0;
            bool is_favorite = false;

        public:
            Manga(const std::filesystem::path& path);
            std::filesystem::path getCoverImagePath() const;

    };

}