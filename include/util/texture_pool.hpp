#pragma once
#include "SFML/Graphics.hpp"
#include <filesystem>
#include <iostream>
#include <memory>
#include <map>


namespace mr {

    typedef std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TextureMap;

    class TexturePool {

        private:
            static TextureMap textureMap;
        
        public:
            static void load(sf::Sprite* sprite, const std::filesystem::path& path);
            static sf::Texture* create(const std::filesystem::path& path);
            static void destroy(const std::filesystem::path& path);
        

    };
    
} // namespace mr
