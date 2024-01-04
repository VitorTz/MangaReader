#include "../../include/scene/reader.hpp"



re::Reader::Reader(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::ReaderId, changeScene) {
    re::Manga* manga = re::globals::mangaByName.at(re::globals::currentManga);
    re::MangaComponent* mangaComponent = new re::MangaComponent(manga);
    this->componentGroup.add(mangaComponent);
}


void re::Reader::update(const float& dt) {
    re::Scene::update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->changeScene(re::SceneId::LibraryId);
}