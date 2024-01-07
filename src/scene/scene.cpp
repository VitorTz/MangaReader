#include "../../include/scene/scene.hpp"



re::Scene::Scene(
    const re::SceneId& sceneId,
    const re::ChangeScene& changeScene
) : sceneId(sceneId),
    changeScene(changeScene) {

    }


re::Scene::~Scene() {

}


void re::Scene::update(const float& dt) {
    if (re::globals::screenHasFocus)
        this->componentGroup.update(dt);
}


void re::Scene::draw(sf::RenderWindow& window) {
    this->componentGroup.draw(window);
}