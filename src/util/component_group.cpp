#include "../../include/util/component_group.hpp"


re::ComponentGroup::ComponentGroup() {

}


re::ComponentGroup::~ComponentGroup() {
    for (const auto& pair : this->componentMap) 
        delete pair.second;
}


void re::ComponentGroup::add(re::Component* c) {
    this->componentMap.insert({c->getName(), c});
}


void re::ComponentGroup::rmv(const std::string& s) {
    if (this->componentMap.find(s) != this->componentMap.end()) {
        re::Component* c = this->componentMap.at(s);
        this->componentMap.erase(s);
        delete c;
    }
}


re::Component* re::ComponentGroup::get(const std::string& s) {
    return this->componentMap.at(s);
}


void re::ComponentGroup::update(const double& dt) {
    for (const auto& pair : this->componentMap)
        pair.second->update(dt);
}


void re::ComponentGroup::draw(sf::RenderWindow& window) {
    for (const auto& pair : this->componentMap)
        pair.second->draw(window);
}