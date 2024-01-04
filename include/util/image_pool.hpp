#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <vector>
#include <string>
#include "util.hpp"


namespace re {


    class ImagePool {

        private:
            static std::map<std::string, sf::Texture*> images;
        
        public:
            static sf::Texture* get(const std::string& imagePath);
            static void load(const std::string& image);
            static void loadImages(const std::vector<std::string>& images);
            static void rmv(const std::string& imagePath);
            static void rmvAll();
            static std::size_t sizeImages();

    };

    
} // namespace re

