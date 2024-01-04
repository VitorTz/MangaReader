#include "../../include/util/image_pool.hpp"


std::map<std::string, sf::Texture*> re::ImagePool::images;


sf::Texture* re::ImagePool::get(const std::string& s) {
    if (re::ImagePool::images.find(s) == re::ImagePool::images.end()) {
        sf::Texture* t = new sf::Texture();
        t->loadFromFile(s);
        re::ImagePool::images.insert({s, t});
    }
    return re::ImagePool::images.at(s);
}


void re::ImagePool::rmv(const std::string& s) {
    if (re::ImagePool::images.find(s) != re::ImagePool::images.end()) {
        sf::Texture* t = re::ImagePool::images.at(s);
        re::ImagePool::images.erase(s);
        delete t;        
    }
}