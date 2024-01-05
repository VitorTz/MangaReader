#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../style/border_style.hpp"
#include "../util/transform.hpp"



namespace re {

    class Border {

        private:
            const re::Style::BorderStyle style;
            sf::RectangleShape rect;

        public:
            Border(const re::Style::BorderStyle& style);
            void draw(sf::RenderWindow& window, const re::Transform& transform);

    };
    
} // namespace re
