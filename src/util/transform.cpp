#include "../../include/util/transform.hpp"


re::Transform::Transform(

) : scale(1.f, 1.f) {
    
}


re::Transform::Transform(
    const sf::Vector2f& pos
) : pos(pos),
    scale(1.f, 1.f) {

    }

re::Transform::Transform(
    const sf::Vector2f& pos,
    const sf::Vector2f& size,
    const sf::Vector2f& scale
) : pos(pos),
    size(size),
    scale(scale) {

    }



float re::Transform::left() const {
    return this->pos.x;
}


float re::Transform::bottom() const {
    return this->pos.y + this->size.y;
}


float re::Transform::top() const {
    return this->pos.y;
}


float re::Transform::right() const {
    return this->pos.x + this->size.x;
}


void re::Transform::setLeft(const float left) {
    this->pos.x = left;
}


void re::Transform::setBottom(const float bottom) {
    this->pos.y = bottom - this->size.y;
}


void re::Transform::setTop(const float top) {
    this->pos.y = top;
}


void re::Transform::setRight(const float right) {
    this->pos.x = right - this->size.x;
}


float re::Transform::centerX() const {
    return this->pos.x + this->size.x / 2;
}


float re::Transform::centerY() const {
    return this->pos.y + this->size.y / 2;
}


void re::Transform::setCenterX(const float x) {
    this->pos.x = x - this->size.x / 2;
}


void re::Transform::setCenterY(const float y) {
    this->pos.y = y - this->size.y / 2;
}


sf::Vector2f re::Transform::center() const {
    return {this->centerX(), this->centerY()};
}


void re::Transform::setCenter(const sf::Vector2f& v) {
    this->setCenterX(v.x);
    this->setCenterY(v.y);
}


void re::Transform::moveX(const float x) {
    this->pos.x += x;
}


void re::Transform::moveY(const float y) {
    this->pos.y += y;
}


void re::Transform::move(const sf::Vector2f& v) {
    this->pos.x += v.x;
    this->pos.y += v.y;
}


bool re::Transform::collide(const re::Transform& t) {
    if (t.left() > this->right() || t.right() < this->left())
        return false;
    
    if (t.bottom() < this->top() || t.top() > this->bottom())
        return false;
    return true;
}


float re::Transform::width() const {
    return this->size.x;
}


float re::Transform::height() const {
    return this->size.y;
}


void re::Transform::setWidth(const float width) {
    this->size.x = width;
}


void re::Transform::setHeight(const float height) {
    this->size.y = height;
}


