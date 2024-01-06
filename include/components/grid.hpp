#pragma once
#include "component.hpp"
#include "grid_item.hpp"
#include "border.hpp"


namespace re {

    typedef struct CurrentGridItem {
        re::GridItem* item;
        std::size_t index;
        std::size_t line;        
    } CurrentGridItem;


    class Grid : public re::Component {

        private:
            const sf::Vector2f pos;
            const std::size_t columns;
            const std::size_t gap;
            re::Border border;
            re::CurrentGridItem currentItem;            
            re::Timer timer;
            std::vector<re::GridItem*> items;
        
        private:
            void changeCurrentItem(const std::size_t& index);
            void resetPos();
            void deleteManga();
            void favoriteManga();
            void sortItemsByFavorite();

        public:
            Grid(
                const sf::Vector2f& pos,
                const std::size_t& columns,
                const std::size_t& gap
            );
            ~Grid() override;
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;
            std::string getCurrentManga();
    };

} // namespace re
