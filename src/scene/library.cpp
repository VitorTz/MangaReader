#include "../../include/scene/my_library.hpp"



og::MyLibrary::MyLibrary(
    const og::ChangeScene& changeScene
) : og::Scene(og::SceneId::Library, changeScene) {

}


og::MyLibrary::~MyLibrary() {

}

void og::MyLibrary::update(const double dt) {
    og::Scene::update(dt);
}