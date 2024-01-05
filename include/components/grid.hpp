#pragma once
#include "component.hpp"
#include "grid_item.hpp"
#include "border.hpp"


namespace re {

    class Grid : public re::Component {

        private:
            const sf::Vector2f pos;
            re::Border border;
            re::GridItem* currentGridItem;
            std::size_t currentGridIndex;
            re::Timer timer;
            std::vector<re::GridItem*> items;
        
        private:
            bool changeCurrentItem(const std::size_t& index);
            void changeToNextItem();
            void changeToPreviousItem();
            void changeToUpColumnItem();
            void changeToDownColumnItem();
            void moveUp();
            void moveDown();

        public:
            Grid(const sf::Vector2f& pos);
            ~Grid() override;
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;
            std::string getCurrentManga();
    };

} // namespace re
