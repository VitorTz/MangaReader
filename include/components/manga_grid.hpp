#ifndef MANGA_READER_MANGA_GRID_HPP
#define MANGA_READER_MANGA_GRID_HPP
#include "component.hpp"
#include "manga_cover.hpp"


namespace re {

    class MangaGrid : public re::Component {

        private:
            const sf::Vector2f pos;
            const std::size_t columns;
            std::size_t currentMangaIndex;
            std::vector<re::MangaCover*> mangaCoverList;
            re::Timer timer;
        
        private:
            void setGridPos();
            void handleInput(const double dt);
            void changeSelectedManga(const std::size_t& index);
            void moveGridUp();
            void moveGridDown();
            void fixPos();
            void favoriteCurrentManga();

        public:
            MangaGrid(const sf::Vector2f& pos);
            ~MangaGrid() override;
            void update(const double& dt) override;
            void draw(sf::RenderWindow& window) override;
            re::Manga* getCurrentSelectedManga();

    };
    
} // namespace re




#endif