#include "../../include/scene/reader.hpp"


re::Reader::Reader(
    const re::ChangeScene& changeScene 
) : re::Scene(re::SceneId::ReaderId, changeScene) {
    std::shared_ptr<re::Manga> manga = re::mangaMap.at(re::currentManga);
    this->componentMap.insert(
        {
            manga->name, 
            std::make_unique<re::MangaComponent>(manga)
        }
    );
}

void re::Reader::update(const float& dt) {
    re::Scene::update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        re::currentManga = "";
        this->changeScene(re::SceneId::LibraryId);
    }
}