#include "../../include/component/border.hpp"


re::Border::Border(
    const sf::Vector2f& size,
    const std::size_t thickness,
    const sf::Color& color
) : size(size),
    thickness(thickness) {
    this->rect.setFillColor(color);    
}


void re::Border::setSize(const sf::Vector2f& size) {
    this->size = size;
}

void re::Border::draw(sf::RenderWindow& window, const sf::Vector2f& pos) {
    const float t = (float) this->thickness;
    const float right = pos.x + size.x;
    const float bottom = pos.y + size.y;

    this->rect.setPosition(pos);
    this->rect.setSize({this->size.x, t});
    window.draw(this->rect);

    this->rect.setPosition({pos.x, bottom - t});
    window.draw(this->rect);

    this->rect.setSize({t, size.y});
    this->rect.setPosition(pos);
    window.draw(this->rect);

    this->rect.setPosition({right - t, pos.y});
    window.draw(this->rect);
    
}