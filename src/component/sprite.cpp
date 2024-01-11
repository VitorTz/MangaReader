#include "../../include/component/sprite.hpp"


re::Sprite::Sprite(
    const std::string& path
) : re::Sprite(path, {}) {

}


re::Sprite::Sprite(
    const std::string& path,
    const re::Transform& transform 
) : re::Component(path, transform) {
    
}


re::Sprite::~Sprite() {
    re::TexturePool::rmv(this->name);
}


void re::Sprite::load() {
    re::TexturePool::load(this->name, this->sprite);
    this->transform.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}

void re::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->transform.pos);
    window.draw(this->sprite);
}