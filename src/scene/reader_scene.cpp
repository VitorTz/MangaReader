#include "../../include/scene/reader_scene.hpp"



og::ReaderScene::ReaderScene(
    const og::ChangeScene& changeScene
) : og::Scene(og::SceneId::Reader, changeScene) {

}



void og::ReaderScene::update(const double dt) {
    og::Scene::update(dt);
}