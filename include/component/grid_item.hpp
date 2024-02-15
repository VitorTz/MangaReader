#ifndef E3C6B64D_9874_4AE0_8705_8E77EA913AD1
#define E3C6B64D_9874_4AE0_8705_8E77EA913AD1
#include "component.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "paragraph.hpp"
#include "../model/manga.hpp"



namespace re {

    class Bookmark {

        private:
            re::Sprite b0;
            re::Sprite b1;

        public:
            Bookmark();
            void draw(
                sf::RenderWindow& window,
                const re::Transform& t, 
                const bool& isFavorite
            );

    };

    class GridItem : public re::Component {

        private:
            static re::Bookmark bookmark;

        private:
            std::shared_ptr<re::Manga> manga;
            re::Sprite image;
            re::Paragraph text;
            re::Rect rect;
            re::Text numChapters;
        
        public:
            GridItem(const std::shared_ptr<re::Manga> manga);
            void setPos(const sf::Vector2f& pos);
            void draw(sf::RenderWindow& window) override;
            const std::shared_ptr<re::Manga>& getManga(); 

    };

    
} // namespace re


#endif /* E3C6B64D_9874_4AE0_8705_8E77EA913AD1 */
