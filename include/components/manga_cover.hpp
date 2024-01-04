#ifndef MANGA_READER_MANGA_COVER_HPP
#define MANGA_READER_MANGA_COVER_HPP
#include "component.hpp"
#include "sprite.hpp"
#include "border.hpp"
#include "text.hpp"
#include "rect.hpp"


namespace re {


    class MangaCover : public re::Component {

        private:
            re::Manga* manga;
            std::vector<re::Text*> text;
            re::Rect* rect;
            re::Border* border;
            re::Sprite* sprite;
            re::StateId state;
        
        private:
            void setUpText();            

        public:
            MangaCover(re::Manga* manga);            
            ~MangaCover() override;
            void setPos(const sf::Vector2f& pos);            
            void draw(sf::RenderWindow& window) override;
            void setState(const re::StateId& state);
            void moveY(const double& y);
            re::Manga* getManga();
    };

    
    
} // namespace re


#endif
