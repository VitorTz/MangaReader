#include "../../include/util/texture_pool.hpp"


mr::TextureMap mr::TexturePool::textureMap;


void mr::TexturePool::load(sf::Sprite* sprite, const std::filesystem::path& path) {
    sf::Texture* t = mr::TexturePool::create(path);
    sprite->setTexture(*t);
}


sf::Texture* mr::TexturePool::create(const std::filesystem::path& path) {
    if (mr::TexturePool::textureMap.find(path) == mr::TexturePool::textureMap.end()) {
        const auto& [pair, success] = mr::TexturePool::textureMap.insert(
            {
                path,
                std::make_unique<sf::Texture>()
            }  
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);        
        std::cout << "[TEXTURE CREATED] [" << path << "]\n";
    }
    return mr::TexturePool::textureMap.at(path).get();
}


void mr::TexturePool::destroy(const std::filesystem::path& path) {
    if (mr::TexturePool::textureMap.find(path) != mr::TexturePool::textureMap.end()) {
        mr::TexturePool::textureMap.erase(path);
        std::cout << "[TEXTURE DELETED] [" << path << "]\n";
    }
}