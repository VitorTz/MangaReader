#ifndef MANGA_READER_IMAGE_HPP
#define MANGA_READER_IMAGE_HPP
#include <filesystem>
#include "../util/util.hpp"
#include "../util/image_pool.hpp"


namespace re {

    class Image {

        public:
            const std::filesystem::path path;
            const std::string name;
            const double num;

        public:
            Image(const std::filesystem::path& path);
            ~Image();

    };

} // namespace re


#endif