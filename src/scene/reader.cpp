#include "../../include/scene/reader.hpp"



og::Reader::Reader(
    const og::ChangeScene& changeScene
) : og::Scene(og::SceneId::ReaderId, changeScene) {

}



void og::Reader::update(const double dt) {
    og::Scene::update(dt);
}