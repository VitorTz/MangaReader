#pragma once
#include "scene.hpp"
#include "../util/manga.hpp"
#include "../util/image.hpp"
#include "../util/text.hpp"
#include "../util/timer.hpp"
#include "../util/grid_item.hpp"
#include <cstddef>
#include <memory>


namespace mr {


    class LibraryScene : public Scene {

        private:
            const int grid_columns = 4;
            const int grid_padding = 10;
            const sf::Vector2f grid_pos = sf::Vector2f(100.f, 60.f);
            const sf::Vector2f grid_item_size = sf::Vector2f(260.f, 364.f);
            const std::vector<sf::Keyboard::Key> keys = {
                sf::Keyboard::Left,
                sf::Keyboard::Right,
                sf::Keyboard::Up,
                sf::Keyboard::Down,
                sf::Keyboard::Enter,
                sf::Keyboard::F
            };
        
        private:
            mr::Timer timer = mr::Timer(10);
            mr::Text no_mangas_txt = mr::Text("No Mangas", mr::style::TXT_HEADER);

        private:
            std::vector<std::unique_ptr<mr::Manga>> mangas;
            std::vector<std::unique_ptr<mr::GridItem>> grid;
        
        private:
            void update_grid_pos();    
            void favorite_manga();
            void change_selected_item(std::size_t index);        
            std::size_t item_index = 0;

        public:
            LibraryScene(
                const mr::ChangeScene& changeScene,
                const mr::SceneInfo& scene_info
            );
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
        
    };

}