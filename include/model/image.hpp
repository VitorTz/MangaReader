#pragma once
#include <string>
#include <filesystem>
#include "../util/util.hpp"


namespace re {

    class Image {


        public:
            const std::string path;
            const std::size_t num;
        
        public:
            Image(const std::filesystem::path& _path);

    };
    
} // namespace re
