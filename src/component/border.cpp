#include "../../include/component/border.hpp"


re::Border::Border(
    const re::Transform& transform,
    const std::size_t& thickness,
    const sf::Color& color
) : re::Component("Border", transform),
    thickness(thickness) {
    this->rect.setFillColor(color);    
}


const std::size_t& re::Border::getThickness() const {
    return this->thickness;
}

void re::Border::setThickness(const std::size_t& thickness) {
    this->thickness = thickness;
}


void re::Border::draw(sf::RenderWindow& window) {
    const float t = (float) this->thickness;
    this->rect.setPosition(this->transform.pos);
    
    this->rect.setSize({this->transform.width(), t});
    window.draw(this->rect);

    this->rect.setPosition({this->transform.left(), this->transform.bottom() - t});
    window.draw(this->rect);

    this->rect.setSize({t, this->transform.height()});
    this->rect.setPosition(this->transform.pos);
    window.draw(this->rect);

    this->rect.setPosition({this->transform.right() - t, this->transform.top()});
    window.draw(this->rect);

}