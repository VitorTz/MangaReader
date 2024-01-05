#pragma once
#include <cmath>
#include "component.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "text.hpp"


namespace re {


    class GridItem : public re::Component {
        
        private:
            re::Manga* manga;
            re::Rect* rect;
            re::Sprite* image;
            std::vector<re::Text*> texts;
        
        private:
            void initTxt();

        public:
            GridItem(re::Manga* manga);            
            ~GridItem();
            void setPos(const sf::Vector2f& pos);
            void draw(sf::RenderWindow& window);
            void moveY(const float& y);
            const std::string& getMangaName() const;

    };
    
} // namespace re
