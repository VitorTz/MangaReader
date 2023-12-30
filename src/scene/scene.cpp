#include "../../include/scene/scene.hpp"



og::Scene::Scene(
    const og::SceneId& sceneId,
    const og::ChangeScene& changeScene
) : sceneId(sceneId), 
    changeScene(changeScene) {

    }


og::Scene::~Scene() {

}


void og::Scene::update(const double dt) {

}


void og::Scene::draw(sf::RenderWindow& window) {

}


const og::SceneId& og::Scene::getSceneId() const {
    return this->sceneId;
}