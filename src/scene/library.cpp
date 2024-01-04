#include "../../include/scene/library.hpp"



re::Library::Library(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::LibraryId, changeScene) {
    re::Manga* manga = re::globals::mangaByName.at("Bought By The Demon Lord Before The Ending");
    re::GridItem* gridItem = new re::GridItem(manga);
    gridItem->setPos({200, 200});
    this->componentGroup.add(gridItem);
}   


void re::Library::update(const float& dt) {
    re::Scene::update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        re::globals::currentManga = "Secret Class";
        this->changeScene(re::SceneId::ReaderId);
    }

}