#include "../../include/components/image.hpp"


og::Image::Image(
    const std::string& path
) : og::Component(path), 
    path(path) {
    
}


og::Image::~Image() {
    og::ImagePool::rmvImage(this->path);
}


void og::Image::loadImage() {
    const og::ImageSource* img = og::ImagePool::getImage(this->path);
    this->rect.setSize((sf::Vector2f) img->texture->getSize());
}


void og::Image::draw(sf::RenderWindow& window) {
    const og::ImageSource* img = og::ImagePool::getImage(this->path);
    img->sprite->setPosition(this->rect.getPos());
    window.draw(*img->sprite);
}
