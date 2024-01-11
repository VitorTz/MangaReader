#include "../../include/scene/scene.hpp"


re::Scene::Scene(
    const re::SceneId& id,
    const re::ChangeScene& changeScene
) : id(id),
    changeScene(changeScene) {

    }


re::Scene::~Scene() {
    
}


void re::Scene::update(const float& dt) {
    for (const auto& [componentName, component] : this->componentMap)
        component->update(dt);
}

void re::Scene::draw(sf::RenderWindow& window) {
    for (const auto& [componentName, component] : this->componentMap)
        component->draw(window);
}