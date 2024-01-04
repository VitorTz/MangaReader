#include "../../include/components/sprite.hpp"



re::Sprite::Sprite(
    const std::string& imagePath,
    const re::Transform& transform
) : re::Component(imagePath, transform) {
    sf::Texture* t = re::ImagePool::get(this->name);
    this->sprite.setTexture(*t);
    this->transform.setSize((sf::Vector2f) t->getSize());
}


re::Sprite::Sprite(
    const std::string& imagePath 
) : re::Sprite(imagePath, {}) {

}


re::Sprite::~Sprite() {
    re::ImagePool::rmv(this->name);
}


void re::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->transform.getPos());
    window.draw(this->sprite);
}