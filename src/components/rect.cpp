#include "../../include/components/rect.hpp"



re::Rect::Rect(
    const std::string& name,
    const re::Transform& t,
    const sf::Color& color
) : re::Component(name, t),
    color(color) {

    }


re::Rect::Rect(
    const std::string& name,
    const sf::Color& color
) : re::Component(name),
    color(color) {

}


void re::Rect::changeColor(const sf::Color& color) {
    this->color = color;
}


void re::Rect::draw(sf::RenderWindow& window) {
    this->rect.setPosition(this->transform.pos);
    this->rect.setSize(this->transform.size);
    this->rect.setScale(this->transform.scale);
    this->rect.setFillColor(this->color);
    window.draw(this->rect);
}