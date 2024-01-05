#include "../../include/components/border.hpp"


re::Border::Border(
    const re::Style::BorderStyle& style
) : style(style) {
    this->rect.setFillColor(style.color);
}


void re::Border::draw(
    sf::RenderWindow& window, 
    const re::Transform& transform
) {
    const sf::Vector2f& pos = transform.getPos();
    const sf::Vector2f& size = transform.getSize();
    const float thickness = (float) style.thickness;

    this->rect.setPosition(pos);
    this->rect.setSize({size.x, thickness});
    window.draw(this->rect);

    this->rect.setPosition({pos.x, transform.bottom() - thickness});
    window.draw(this->rect);

    this->rect.setPosition({pos});
    this->rect.setSize({thickness, size.y});
    window.draw(this->rect);

    this->rect.setPosition({transform.right() - thickness, pos.y});
    window.draw(this->rect);

}