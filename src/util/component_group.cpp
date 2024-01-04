#include "../../include/util/component_group.hpp"
#include <iostream>


re::ComponentGroup::ComponentGroup() {

}


re::ComponentGroup::~ComponentGroup() {
    re::deletePtrMap(this->componentMap);
}


void re::ComponentGroup::add(re::Component* c) {
    this->componentMap.insert({c->name, c});
}


void re::ComponentGroup::rmv(const std::string& name) {
    if (this->componentMap.find(name) != this->componentMap.end()) {
        re::Component* c = this->get(name);
        delete c;
        this->componentMap.erase(name);
    }
}


re::Component* re::ComponentGroup::get(const std::string& name) {
    return this->componentMap.at(name);
}


void re::ComponentGroup::update(const float& dt) {
    for (const auto& pair : this->componentMap) {
        pair.second->update(dt);
    }
}


void re::ComponentGroup::draw(sf::RenderWindow& window) {
    for (const auto& pair : this->componentMap) {
        pair.second->draw(window);
    }
}