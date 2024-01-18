#include "../../include/component/sprite.hpp"


re::Sprite::Sprite(
    const std::filesystem::path& path
) : re::Sprite(path, { }) {

}


re::Sprite::Sprite(
    const std::filesystem::path& path,
    const re::Transform& transform 
) : re::Component(path, transform) {
    
}


re::Sprite::~Sprite() {
    re::TexturePool::rmv(this->name);
}


void re::Sprite::setMaxWidth(const float maxWidth) {
    if (this->transform.size.x < maxWidth) {
        return;
    }
    const float xScale = maxWidth / this->transform.size.x;
    this->transform.scale.x = xScale;
    this->transform.scale.y = xScale;
    this->transform.size.x *= xScale;
    this->transform.size.y *= xScale;
}

void re::Sprite::load() {
    re::TexturePool::load(this->name, this->sprite);
    this->transform.size = (sf::Vector2f) this->sprite.getTexture()->getSize();
}


void re::Sprite::load(const float maxWidth) {
    this->load();
    this->setMaxWidth(maxWidth);
}

void re::Sprite::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->transform.pos);
    this->sprite.setScale(this->transform.scale);
    window.draw(this->sprite);
}