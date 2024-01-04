#include "../../include/components/sprite.hpp"



re::Sprite::Sprite(
    const std::string& imagePath
) : re::Sprite(imagePath, {}) {
    
}


re::Sprite::Sprite(
    const std::string& imagePath,
    const re::Transform& transform
) : re::Component(imagePath, transform) {
    sf::Texture* t = re::ImagePool::get(this->getName());
    this->sprite.setTexture(*t);
    this->transform.size = (sf::Vector2f) t->getSize();
}


re::Sprite::~Sprite() {
    re::ImagePool::rmv(this->getName());
}


void re::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->transform.pos);
    this->sprite.setScale(this->transform.scale);
    window.draw(this->sprite);
}