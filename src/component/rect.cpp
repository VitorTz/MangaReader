#include "../../include/component/rect.hpp"


re::Rect::Rect(
    const re::Transform& transform,
    const sf::Color& color
) : re::Component("Rect", transform) {
    this->rect.setFillColor(color);
    this->rect.setSize(transform.size);
}


inline void re::Rect::changeColor(const sf::Color& color) {
    this->rect.setFillColor(color);
}


void re::Rect::draw(sf::RenderWindow& window) {
    this->rect.setSize(this->transform.size);
    this->rect.setPosition(this->transform.pos);
    window.draw(this->rect);
}