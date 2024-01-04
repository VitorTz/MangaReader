#include "../../include/util/image_pool.hpp"


std::map<std::string, sf::Texture*> re::ImagePool::images;

void re::ImagePool::load(const std::string& imagePath) {
    if (re::ImagePool::images.find(imagePath) == re::ImagePool::images.end()) {
        sf::Texture* t = new sf::Texture();
        t->loadFromFile(imagePath);
        re::ImagePool::images.insert({imagePath, t});
    }
}


void re::ImagePool::loadImages(const std::vector<std::string>& images) {
    for (const std::string& s : images)
        re::ImagePool::load(s);
}


sf::Texture* re::ImagePool::get(const std::string& imagePath) {
    re::ImagePool::load(imagePath);
    return re::ImagePool::images.at(imagePath);
}


void re::ImagePool::rmv(const std::string& imagePath) {
    if (re::ImagePool::images.find(imagePath) != re::ImagePool::images.end()) {        
        sf::Texture* t = re::ImagePool::images.at(imagePath);
        delete t;        
        re::ImagePool::images.erase(imagePath);
    }
}


void re::ImagePool::rmvAll() {
    re::deletePtrMap(re::ImagePool::images);
}

std::size_t re::ImagePool::sizeImages() {
    return re::ImagePool::images.size();
}

