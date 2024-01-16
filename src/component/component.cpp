#include "../../include/component/component.hpp"



re::Component::Component(
    const std::string& name,
    const re::Transform& transform 
) : name(name),
    transform(transform) {

    }


re::Component::Component(
    const std::string& name 
) : re::Component(name, {}) {

}


re::Component::~Component() = default;


void re::Component::update([[maybe_unused]] const float dt) {
 
}


void re::Component::draw([[maybe_unused]] sf::RenderWindow& window) {
 
}