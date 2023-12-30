#include "../../include/scene/scene.hpp"



og::Scene::Scene(
    const og::SceneId& sceneId,
    const og::ChangeScene& changeScene
) : sceneId(sceneId), 
    changeScene(changeScene) {

    }


og::Scene::~Scene() {
    for (auto& pair : this->componentMap) 
        delete pair.second;
}


void og::Scene::update(const double dt) {
    for (auto& pair : this->componentMap) 
        pair.second->update(dt);
}


void og::Scene::draw(sf::RenderWindow& window) {
    for (auto& pair : this->componentMap) 
        pair.second->draw(window);
}


const og::SceneId& og::Scene::getSceneId() const {
    return this->sceneId;
}


void og::Scene::addComponent(og::Component* c) {
    this->componentMap.insert({c->getName(), c});
}


void og::Scene::rmvComponent(const std::string& n) {
    if (this->componentMap.find(n) != this->componentMap.end()) {
        og::Component* c = this->componentMap.at(n);
        this->componentMap.erase(n);
        delete c;
    }
}


og::Component* og::Scene::getComponent(const std::string& n) const {
    return this->componentMap.at(n);
}