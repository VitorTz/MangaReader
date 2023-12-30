#include "../../include/components/component.hpp"


og::Component::Component(
    const std::string& name
) : name(name) {
    
}


og::Component::Component(
    const std::string& name,
    const og::Rect& rect
) : name(name),
    rect(rect) {

    }


og::Component::~Component() {

}


void og::Component::update(const double dt) {
    return;
}


void og::Component::draw(sf::RenderWindow& window) {
    return;
}


const std::string& og::Component::getName() const {
    return this->name;
}


og::Rect& og::Component::getRect() {
    return this->rect;
}