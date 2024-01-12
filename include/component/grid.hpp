#ifndef F61F180F_7AAF_4110_B204_3E6D1B164B2C
#define F61F180F_7AAF_4110_B204_3E6D1B164B2C
#include <vector>
#include <memory>
#include <functional>
#include "component.hpp"
#include "grid_item.hpp"
#include "border.hpp"
#include "text.hpp"
#include "../util/notification_manager.hpp"


namespace re {

    class Grid : public re::Component {

        private:
            std::vector<std::unique_ptr<re::GridItem>> items;
            const sf::Vector2f pos;
            const std::size_t columns;
            const std::size_t gap;
            const sf::Vector2f itemSize;
            re::Text text;
            re::Border border;
            std::size_t currentItemIndex;
        
        private:
            void resetPos();      
            void sortItemsByFavorite();  
            void favoriteCurrentItem();    
            void changeCurrentItem(const std::size_t& n);
            std::size_t indexOfItem(const std::string& mangaName);
        
        public:
            Grid(
                const sf::Vector2f& pos,
                const std::size_t& columns,
                const std::size_t& gap                
            );
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;
            std::string getItem() const;
    };
    
} // namespace re


#endif /* F61F180F_7AAF_4110_B204_3E6D1B164B2C */
