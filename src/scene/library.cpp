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
    const std::string mangaName = grid->getItem();
    if (!mangaName.empty()) {
        re::globals::currentManga = mangaName;        
        this->changeScene(re::SceneId::ReaderId);
    }
}
