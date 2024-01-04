#include "../../include/scene/reader.hpp"


re::Reader::Reader(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::ReaderId, changeScene) {
    re::MangaComponent* mangaComponent = new re::MangaComponent(
        re::globals::mangaByName.at(re::globals::currentMangaName)
    );
    mangaComponent->load();
    this->add(mangaComponent);
}


void re::Reader::update(const double& dt) {
    re::Scene::update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->changeScene(re::SceneId::LibraryId);
}