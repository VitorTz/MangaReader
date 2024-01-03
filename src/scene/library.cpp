#include "../../include/scene/library.hpp"
#include <iostream>


re::Library::Library(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::LibraryId, changeScene) {
    re::Manga* manga = re::globals::mangaByName.at("Sextudy Group");
    re::MangaComponent* mangaComponent = new re::MangaComponent(manga);
    mangaComponent->load();
    this->add(mangaComponent);
}


void re::Library::update(const double dt) {
    re::Scene::update(dt);
}


