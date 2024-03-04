#include "../../include/scene/reader.hpp"


mr::Reader::Reader(
    const mr::ChangeScene& change_scene
) : mr::Scene(mr::SceneId::ReaderSceneId, change_scene) {

}


void mr::Reader::update(const double dt) {
    mr::Scene::update(dt);
}


void mr::Reader::draw(sf::RenderWindow& window) {
    mr::Scene::draw(window);
}
