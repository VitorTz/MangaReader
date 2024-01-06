#include "../../include/scene/library.hpp"


re::Library::Library(
    const re::ChangeScene& changeScene
) : re::Scene(re::SceneId::LibraryId, changeScene) {
    re::Grid* grid = new re::Grid({140, 20}, 4, 10);
    this->componentGroup.add(grid);
}   


void re::Library::update(const float& dt) {
    re::Scene::update(dt);
    re::Grid* grid = (re::Grid*) this->componentGroup.get("Grid");
    const std::string mangaName = grid->getCurrentManga();
    if (!mangaName.empty()) {
        re::globals::currentManga = mangaName;
        this->changeScene(re::SceneId::ReaderId);
    }
        

}