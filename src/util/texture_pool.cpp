#include "../../include/util/texture_pool.hpp"


std::map<std::string, std::unique_ptr<sf::Texture>> re::TexturePool::textureMap;


std::mutex re::TexturePool::m;


void re::TexturePool::load(const std::string& path) {
    re::TexturePool::m.lock();
    const bool contains = re::contains(re::TexturePool::textureMap, path);
    re::TexturePool::m.unlock();

    if (!contains) {
        re::TexturePool::m.lock();
        const auto [pair, success] = re::TexturePool::textureMap.insert(
            {path, std::make_unique<sf::Texture>()}
        );
        re::TexturePool::m.unlock();
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);
    }

}

void re::TexturePool::load(const std::string& path, sf::Sprite& sprite) {
    re::TexturePool::load(path);
    sprite.setTexture(*re::TexturePool::textureMap.at(path));
}

void re::TexturePool::rmv(const std::string& path) {
    if (re::contains(re::TexturePool::textureMap, path))
        re::TexturePool::textureMap.erase(path);
}


void re::TexturePool::rmvAll() {
    re::TexturePool::textureMap.clear();
}