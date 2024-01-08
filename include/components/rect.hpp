#pragma once
#include "component.hpp"


namespace re {

    class Rect : public re::Component {

        private:
            sf::RectangleShape rect;
            sf::Color color;

        public:
            Rect(const sf::Color& color);
            Rect(
                const re::Transform& transform, 
                const sf::Color& color
            );
            Rect(
                const std::string& name,
                const re::Transform& transform, 
                const sf::Color& color
            );
            void changeColor(const sf::Color& color);
            void draw(sf::RenderWindow& window) override;

    };  
    
} // namespace re
