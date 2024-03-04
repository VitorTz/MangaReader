#include "../../include/util/texture_pool.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <memory>


mr::TextureMap mr::TexturePool::textureMap;


sf::Texture* mr::TexturePool::get(const std::filesystem::path &path) {
    if (mr::TexturePool::textureMap.find(path) == mr::TexturePool::textureMap.end()) {
        const auto& [pair, success] = mr::TexturePool::textureMap.insert(
            {
                path,
                std::make_unique<sf::Texture>()
            }
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);
        std::cout << "[TEXTURE LOAD] [" << path << "]\n";
    }
    return mr::TexturePool::textureMap.at(path).get();
}


void mr::TexturePool::load(sf::Sprite *sprite, const std::filesystem::path &path) {
    sf::Texture* t = mr::TexturePool::get(path);
    sprite->setTexture(*t);
}


void mr::TexturePool::erase(const std::filesystem::path &path) {
    if (mr::TexturePool::textureMap.find(path) != mr::TexturePool::textureMap.end()) {
        mr::TexturePool::textureMap.erase(path);
        std::cout << "[TEXTURE UNLOAD] [" << path << "]\n";
    }
}