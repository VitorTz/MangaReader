#ifndef F61F180F_7AAF_4110_B204_3E6D1B164B2C
#define F61F180F_7AAF_4110_B204_3E6D1B164B2C
#include <vector>
#include <memory>
#include <functional>
#include "component.hpp"
#include "grid_item.hpp"
#include "border.hpp"


namespace re {

    typedef struct Item {
        const std::string name;
        const bool isSelected;
    } Item;

    class Grid : public re::Component {

        private:
            std::vector<std::unique_ptr<re::GridItem>> items;
            const sf::Vector2f pos;
            const std::size_t columns;
            const std::size_t gap;
            const sf::Vector2f itemSize;
            re::Border border;
            std::size_t currentItemIndex;
        
        private:
            void resetPos();            
            void changeCurrentItem(const std::size_t& n);
        
        public:
            Grid(
                const sf::Vector2f& pos,
                const std::size_t& columns,
                const std::size_t& gap                
            );
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;
            re::Item getItem() const;
    };
    
} // namespace re


#endif /* F61F180F_7AAF_4110_B204_3E6D1B164B2C */
