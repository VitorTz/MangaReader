#ifndef B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2
#define B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2
#include "component.hpp"


namespace re {


    class Border : public re::Component {

        private:
            sf::RectangleShape rect;
            std::size_t thickness;

        public:
            Border(
                const re::Transform& transform,
                const std::size_t& thicknes,
                const sf::Color& color
            );
            const std::size_t& getThickness() const;
            void setThickness(const std::size_t& thickness);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2 */
