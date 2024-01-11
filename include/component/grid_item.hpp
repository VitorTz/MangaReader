#ifndef E3C6B64D_9874_4AE0_8705_8E77EA913AD1
#define E3C6B64D_9874_4AE0_8705_8E77EA913AD1
#include "component.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "paragraph.hpp"
#include "../model/manga.hpp"



namespace re {


    class GridItem : public re::Component {

        private:
            std::shared_ptr<re::Manga> manga;
            re::Sprite image;
            re::Paragraph text;
            re::Rect rect;
        
        public:
            GridItem(const std::shared_ptr<re::Manga> manga);
            void setPos(const sf::Vector2f& pos);
            void draw(sf::RenderWindow& window) override;

    };

    
} // namespace re


#endif /* E3C6B64D_9874_4AE0_8705_8E77EA913AD1 */
