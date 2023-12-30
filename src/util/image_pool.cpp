#include "../../include/util/image_pool.hpp"


std::map<std::string, og::ImageSource*> og::ImagePool::images;


const og::ImageSource* og::ImagePool::getImage(const std::string& path) {    
    if (og::ImagePool::images.find(path) == og::ImagePool::images.end()) {
        og::ImageSource* img = new og::ImageSource();
        img->sprite = new sf::Sprite();
        img->texture = new sf::Texture();
        img->texture->loadFromFile(path);
        img->sprite->setTexture(*img->texture);
        og::ImagePool::images.insert({path, img});
    }
    return og::ImagePool::images.at(path);
}


void og::ImagePool::rmvImage(const std::string& path) {
    if (og::ImagePool::images.find(path) != og::ImagePool::images.end()) {
        og::ImageSource* img = og::ImagePool::images.at(path);
        og::ImagePool::images.erase(path);
        delete img->texture;
        delete img->sprite;
        delete img;
        std::cout << "Removing " << path << '\n';
    }
}


void og::ImagePool::rmvAll() {
    for (auto& pair : og::ImagePool::images) {
        delete pair.second->texture;
        delete pair.second->sprite;
        delete pair.second;            
        std::cout << "Deleting " << pair.first << '\n';
    }
}