#include "../../include/scene/library.hpp"
#include <iostream>


re::Library::Library(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::LibraryId, changeScene) {
    re::MangaGrid* mangaGrid = new re::MangaGrid({150, 25});
    this->componentGroup.add(mangaGrid);
}


void re::Library::update(const double& dt) {
    re::Scene::update(dt);
    re::MangaGrid* grid = (re::MangaGrid*) this->componentGroup.get("MangaGrid");
    re::Manga* selectedManga = grid->getCurrentSelectedManga();
    if (selectedManga != nullptr) {
        re::globals::currentMangaName = selectedManga->name;
        this->changeScene(re::SceneId::ReaderId);
    }
}