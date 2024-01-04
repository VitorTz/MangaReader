#include "../../include/components/component.hpp"


re::Component::Component(
    const std::string& name,
    const re::Transform& t
) : name(name),
    transform(t) {

    }


re::Component::Component(
    const std::string& name
) : name(name) {

}


re::Component::~Component() {

}


void re::Component::update(const float& dt) {
    return;
}


void re::Component::draw(sf::RenderWindow& window) {
    return;
}

