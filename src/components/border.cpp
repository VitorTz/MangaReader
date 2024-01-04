#include "../../include/components/border.hpp"


re::Border::Border(
    const re::Transform& transform,
    const re::BorderStyle& style
) : transform(transform),
    style(style),
    state(re::StateId::Inactive) {

    }



void re::Border::setStatus(const re::StateId& status) {
    this->state = status;
}


void re::Border::draw(sf::RenderWindow& window) {
    this->rect.setFillColor(this->style.colorState.get(this->state));
    const float thickness = (float) this->style.thicknessState.get(this->state);

    this->rect.setPosition(this->transform.pos);
    this->rect.setSize({this->transform.size.x, thickness});
    window.draw(this->rect);

    this->rect.setPosition({this->transform.left(), this->transform.bottom() - thickness});
    window.draw(this->rect);

    this->rect.setSize({thickness, this->transform.size.y});
    this->rect.setPosition(this->transform.pos);
    window.draw(this->rect);

    this->rect.setPosition({this->transform.right() - thickness, this->transform.top()});
    window.draw(this->rect);

}