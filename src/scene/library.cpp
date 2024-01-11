#include "../../include/scene/library.hpp"


re::Library::Library(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::LibraryId, changeScene) {
    this->componentMap.insert(
        {
            "Grid",
            std::make_unique<re::Grid>(
                sf::Vector2f(135, 10),
                4, 
                10
            )
        }
    );
}


void re::Library::update(const float& dt) {
    re::Scene::update(dt);
    auto& component = this->componentMap.at("Grid");
    re::Grid* grid = (re::Grid*) component.get();
    const re::Item item = grid->getItem();
    if (item.isSelected) {
        re::currentManga = item.name;
        this->changeScene(re::SceneId::ReaderId);
    }
}
