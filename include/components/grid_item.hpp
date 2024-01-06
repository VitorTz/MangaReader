#pragma once
#include <cmath>
#include "component.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "text.hpp"
#include <iostream>


namespace re {

    class Bookmark {

        private:
            re::Sprite* bookmark_0;
            re::Sprite* bookmark_1;
        
        public:
            Bookmark();
            ~Bookmark();
            void draw(
                sf::RenderWindow& window, 
                const bool& status,
                const sf::Vector2f& pos
            );

    };


    class GridItem : public re::Component {

        private:
            re::Manga* manga;
            re::Rect* rect;
            re::Sprite* image;
            re::Sprite* bookmarkImage;
            re::Bookmark* bookmark;
            std::vector<re::Text*> texts;
        
        private:
            void initTxt();

        public:
            GridItem(re::Manga* manga);            
            ~GridItem();
            void setPos(const sf::Vector2f& pos);
            void draw(sf::RenderWindow& window);
            void moveY(const float& y);
            re::Manga* getManga();

    };

    
} // namespace re
