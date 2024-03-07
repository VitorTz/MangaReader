#pragma once
#include "image.hpp"
#include "manga.hpp"
#include "text.hpp"


namespace mr {
    
    class GridItem {

        public:
            mr::Manga* manga;
            mr::Text text;
            mr::Image image;
            mr::Image favorite_icon_0;
            mr::Image favorite_icon_1;
            sf::RectangleShape text_bg;            
            sf::Vector2f pos;
            sf::Vector2f size;
            bool on_hover = false;

        public:
            explicit GridItem(mr::Manga* manga);
            void setPos(const sf::Vector2f pos);
            void draw(sf::RenderWindow& window);

    };

}
