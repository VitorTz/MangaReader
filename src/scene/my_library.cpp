#include "../../include/scene/my_library.hpp"



og::MyLibrary::MyLibrary(
    const og::ChangeScene& changeScene
) : og::Scene(og::SceneId::MyLibraryId, changeScene) {
    og::Chapter* chapter = new og::Chapter("/mnt/HD1/Manga/Secret Class");
    chapter->load();
    this->addComponent(chapter);
}


void og::MyLibrary::update(const double dt) {
    og::Scene::update(dt);
}