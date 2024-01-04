#include "../../include/scene/scene.hpp"


re::Scene::Scene(
    const re::SceneId& sceneId,
    const re::ChangeScene& changeScene
) : sceneId(sceneId),
    changeScene(changeScene) {

    }



re::Scene::~Scene() {
    for (const auto& pair : this->componentMap)
        delete pair.second;
}


void re::Scene::add(re::Component* c) {
    this->componentMap.insert({c->getName(), c});
}


void re::Scene::rmv(const std::string& s) {
    if (this->componentMap.find(s) != this->componentMap.end()) {
        re::Component* c = this->componentMap.at(s);
        this->componentMap.erase(s);
        delete c;
    }
}


re::Component* re::Scene::get(const std::string& s) {
    return this->componentMap.at(s);
}


void re::Scene::update(const double& dt) {
    for (const auto& pair : this->componentMap)
        pair.second->update(dt);
}


void re::Scene::draw(sf::RenderWindow& window) {
    for (const auto& pair : this->componentMap)
        pair.second->draw(window);
}


const re::SceneId& re::Scene::getSceneId() const {
    return this->sceneId;
}