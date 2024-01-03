#ifndef MANGA_READER_RECT_HPP
#define MANGA_READER_RECT_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include "component.hpp"


namespace re {

    class Rect : public re::Component {

        private:
            sf::RectangleShape rect;
            sf::Color color;
        
        public:
            Rect(
                const std::string& name, 
                const re::Transform& t,
                const sf::Color& color
            );
            Rect(
                const std::string& name,
                const sf::Color& color
            );
            void changeColor(const sf::Color& color);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif