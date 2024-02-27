#include "../../include/scene.hpp"


mr::LibraryScene::LibraryScene(
    const mr::ChangeScene& changeScene
) : mr::Scene(mr::SceneId::LibrarySceneId, changeScene) {
    

    const float item_width = mr::constants::GRID_ITEM_SIZE.x + mr::constants::GRID_PADDING.x;
    const float item_height = mr::constants::GRID_ITEM_SIZE.y + mr::constants::GRID_PADDING.y;
    int i = 0;    
    for (const auto& [manga_name, manga] : mr::globals::mangas) {
        const int col = i % mr::constants::GRID_COLUMNS;
        const int row = i / mr::constants::GRID_COLUMNS;        
        grid.push_back(
            std::make_unique<mr::GridItem>(
                manga_name, 
                manga->get_cover_image(),
                mr::constants::GRID_POS + sf::Vector2f(col * item_width, row * item_height)
            )
        );
        ++i;
    }
    
    change_current_selected_item(0);

}


void mr::LibraryScene::change_current_selected_item(const std::size_t index) {
    if (index >= 0 && index < grid.size()) {
        grid[current_item]->set_on_hover(false);
        grid[index]->set_on_hover(true);
        current_item = index;
    }
}


void mr::LibraryScene::grid_move_down() {
    if (grid.empty()) {
        return;
    }
    sf::Vector2f distance = {0.f, 400.f};
    
    const sf::Vector2f pos_first_item = grid.front()->getPos() + distance;
    if (pos_first_item.y >= mr::constants::SCREEN_HEIGHT - 200) {
        return;
    }
    
    for (std::unique_ptr<mr::GridItem>& item : grid) {
        item->setPos(item->getPos() + distance);
    }
}


void mr::LibraryScene::grid_move_up() {
    
    if (grid.empty()) {
        return;
    }
    
    sf::Vector2f distance = {0.f, -400.f};
    std::unique_ptr<mr::GridItem>& last_item = grid.back();
    const sf::Vector2f last_item_pos = last_item->getPos() + distance;
    const float bottom_last_item = last_item_pos.y + last_item->getSize().y;
    
    if (bottom_last_item <= 200) {
        return;
    }

    for (std::unique_ptr<mr::GridItem>& item : grid) {
        item->setPos(item->getPos() + distance);
    }
}



void mr::LibraryScene::grid_select_item() {
    if (grid.empty()) {
        return;
    }
    mr::globals::manga_reading = grid[current_item]->get_manga_name();
    change_scene(mr::SceneId::ReaderSceneId);
}


void mr::LibraryScene::handle_keyboard() {    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        grid_select_item();
        return;
    }
    
    for (const sf::Keyboard::Key k : keys) {
        if (sf::Keyboard::isKeyPressed(k) && keyboard_timer.check()) {
            switch (k) {
                case sf::Keyboard::Right:
                    change_current_selected_item(current_item + 1);
                    break;
                case sf::Keyboard::Left:
                    change_current_selected_item(current_item - 1);
                    break;
                case sf::Keyboard::Up:
                    change_current_selected_item(current_item - mr::constants::GRID_COLUMNS);
                    grid_move_down();
                    break;
                case sf::Keyboard::Down:
                    change_current_selected_item(current_item + mr::constants::GRID_COLUMNS);
                    grid_move_up();
                    break;                
                default:
                    break;
            }
        }
    }    

}   


void mr::LibraryScene::update(const double dt) {    
    keyboard_timer.update();
    handle_keyboard();
}


void mr::LibraryScene::draw(sf::RenderWindow& window) {
    for (std::unique_ptr<mr::GridItem>& item : grid) {
        item->draw(window);
    }
}