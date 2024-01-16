#ifndef B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2
#define B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


namespace re {


    class Border {

        private:
            sf::Vector2f size;
            std::size_t thickness;
            sf::RectangleShape rect;

        public:
            Border(
                const sf::Vector2f& size,
                const std::size_t thickness,
                const sf::Color& color
            );
            void setSize(const sf::Vector2f& size);
            void draw(
                sf::RenderWindow& window,
                const sf::Vector2f& pos
            );

    };
    
} // namespace re


#endif /* B849C18E_EFFF_4F8E_8DF3_69DD9D8F72C2 */
