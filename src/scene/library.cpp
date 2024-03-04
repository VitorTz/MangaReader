#include "../../include/scene/library.hpp"


mr::Library::Library(
    const mr::ChangeScene& change_scene
) : mr::Scene(mr::SceneId::ReaderSceneId, change_scene) {

}


void mr::Library::update(const double dt) {
    mr::Scene::update(dt);
}


void mr::Library::draw(sf::RenderWindow& window) {
    mr::Scene::draw(window);
}
