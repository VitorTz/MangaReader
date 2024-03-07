#include "../../include/scene/library_scene.hpp"



mr::LibraryScene::LibraryScene(
    const mr::ChangeScene& change_scene,
    [[maybe_unused]] const mr::SceneInfo& scene_info 
) : mr::Scene(mr::SceneId::LibrarySceneId, change_scene, scene_info) {
    std::cout << "[OPEN LIBRARY SCENE]\n";
    no_mangas_txt.center_on_screen();

    for (const auto& p : std::filesystem::directory_iterator(mr::constants::MANGA_DIR))  {
        const std::filesystem::path path = p.path();
        if (std::filesystem::is_directory(path)) {
            mangas.push_back(std::make_unique<mr::Manga>(path));
        }
    }
    
    for (const std::unique_ptr<mr::Manga>& manga : mangas) {
        grid.push_back(std::make_unique<mr::GridItem>(manga.get()));
    }

    if (!grid.empty()) {
        grid[item_index]->on_hover = true;
    }

    update_grid_pos();

}   


void mr::LibraryScene::update_grid_pos() {
    const int y_offset = item_index / grid_columns * ((int) grid_item_size.y + grid_padding);
    for (std::size_t i = 0; i < grid.size(); i++) {
        mr::GridItem* item = grid[i].get();
        const int row = i / grid_columns;
        const int col = i % grid_columns;
        item->setPos(
            {
                grid_pos.x + col * (grid_item_size.x + grid_padding),
                grid_pos.y + row * (grid_item_size.y + grid_padding) + y_offset
            }
        );        
    }

}


void mr::LibraryScene::change_selected_item(const std::size_t index) {
    if (index < grid.size()) {
        grid[item_index]->on_hover = false;
        grid[index]->on_hover = true;
        item_index = index;
        update_grid_pos();
    }
}


void mr::LibraryScene::favorite_manga() {
    mr::Manga* manga = grid[item_index]->manga;
    manga->is_favorite = !manga->is_favorite;
    grid[item_index]->on_hover = false;
    std::sort(
        grid.begin(), grid.end(),
        [](const std::unique_ptr<mr::GridItem>& l, const std::unique_ptr<mr::GridItem>& r) {
            mr::Manga* ml = l->manga;
            mr::Manga* mr = r->manga;
            if (ml->is_favorite && !mr->is_favorite) {
                return true;
            } else if (!ml->is_favorite && mr->is_favorite) {
                return false;
            }
            return ml->name < mr->name;
        }
    );
    change_selected_item(0);
}


void mr::LibraryScene::update([[maybe_unused]] const double dt) {
    if (mangas.empty()) {        
        return;
    }    

    timer.update();

    for (const sf::Keyboard::Key k : keys) {
        if (sf::Keyboard::isKeyPressed(k) && timer.check()) {
            switch (k) {
                case sf::Keyboard::Left:
                    change_selected_item(item_index - 1);
                    break;
                case sf::Keyboard::Right:
                    change_selected_item(item_index + 1);
                    break;
                case sf::Keyboard::Down:
                    change_selected_item(item_index + grid_columns);
                    break;
                case sf::Keyboard::Up:
                    change_selected_item(item_index - grid_columns);
                    break;
                case sf::Keyboard::Enter:
                    change_scene(
                        mr::SceneId::ReaderSceneId, 
                        {{"manga_path", grid[item_index]->manga->path}}
                    );
                    return;
                case sf::Keyboard::F:
                    favorite_manga();
                    break;
                default:
                    break;
            }
        }
    }
    
}


void mr::LibraryScene::draw(sf::RenderWindow& window) {
    if (mangas.empty()) {
        no_mangas_txt.draw(window);
        return;
    }

    for (std::unique_ptr<mr::GridItem>& item : grid) {
        item->draw(window);        
    }
}