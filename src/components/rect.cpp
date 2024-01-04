#include "../../include/components/rect.hpp"


re::Rect::Rect(
    const re::Transform& transform,
    const sf::Color& color
) : re::Rect("Rect", transform, color) { }


re::Rect::Rect(
    const std::string& name,
    const re::Transform& transform,
    const sf::Color& color
) : re::Component(name, transform),
    color(color) {
        this->rect.setFillColor(color);
    }


void re::Rect::changeColor(const sf::Color& color) {
    this->color = color;
    this->rect.setFillColor(color);
}


void re::Rect::draw(sf::RenderWindow& window) {
    this->rect.setPosition(this->transform.getPos());
    this->rect.setSize(this->transform.getSize());
    window.draw(this->rect);
}