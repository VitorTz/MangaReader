#include "../../include/components/image_component.hpp"


re::ImageComponent::ImageComponent(
    re::Image* image
) : re::Component(image->name),
    image(image) {

}


void re::ImageComponent::load() {
    sf::Texture* t = re::ImagePool::get(this->name);
    this->sprite.setTexture(*t);
    this->transform.size = (sf::Vector2f) t->getSize();
}


void re::ImageComponent::draw(sf::RenderWindow& window) {
    this->sprite.setPosition(this->transform.pos);
    this->sprite.setScale(this->transform.scale);
    window.draw(this->sprite);
}