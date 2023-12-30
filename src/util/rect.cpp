#include "../../include/util/rect.hpp"



og::Rect::Rect() {

}


og::Rect::Rect(
    const sf::Vector2f& pos
) : pos(pos) {

}


og::Rect::Rect(
    const sf::Vector2f& pos,
    const sf::Vector2f& size
) : pos(pos),
    size(size) {

    }



const sf::Vector2f& og::Rect::getPos() const {
    return this->pos;
}


const sf::Vector2f& og::Rect::getSize() const {
    return this->size;
}


float og::Rect::left() const {
    return this->pos.x;
}


float og::Rect::top() const {
    return this->pos.y;
}


float og::Rect::bottom() const {
    return this->pos.y + this->size.y;
}


float og::Rect::right() const {
    return this->pos.x + this->size.x;
}


void og::Rect::setLeft(const float left) {
    this->pos.x = left;
}


void og::Rect::setBottom(const float bottom) {
    this->pos.y = bottom - this->size.y;
} 


void og::Rect::setRight(const float right) {
    this->pos.x = right - this->size.x;
}


void og::Rect::setTop(const float top) {
    this->pos.y = top;
}


void og::Rect::setSize(const sf::Vector2f& size) {
    this->size.x = size.x;
    this->size.y = size.y;
}


void og::Rect::setPos(const sf::Vector2f& pos) {
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}


sf::Vector2f og::Rect::center() const {
    return sf::Vector2f(this->centerX(), this->centerY());
}


void og::Rect::setCenter(const sf::Vector2f& center) {
    this->setCenterX(center.x);
    this->setCenterY(center.y);
}


float og::Rect::centerX() const {
    return this->pos.x + this->size.x / 2;
}


float og::Rect::centerY() const {
    return this->pos.y + this->size.y / 2;
}


void og::Rect::setCenterX(const float centerX) {
    this->pos.x = centerX - this->size.x / 2;
}


void og::Rect::setCenterY(const float centerY) {
    this->pos.y = centerY - this->size.y / 2;
}


void og::Rect::move(const float x, const float y) {
    this->pos.x += x;
    this->pos.y += y;
}


void og::Rect::moveY(const float y) {
    this->pos.y += y;
}


void og::Rect::moveX(const float x) {
    this->pos.x += x;
}


bool og::Rect::collideRect(const og::Rect& r) const {
    if (r.left() > this->right() || r.right() < this->left())
        return false;

    if (r.top() > this->bottom() || r.bottom() < this->top())
        return false;

    return true;
}


float og::Rect::width() const {
    return this->size.x;
}


float og::Rect::height() const {
    return this->size.y;
}