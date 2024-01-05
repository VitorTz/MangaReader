#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>



namespace re {

    namespace Style {
        
        class BorderStyle {
            
            public:
                const sf::Color color;
                const std::size_t thickness;
        
            public:
                BorderStyle(
                    const sf::Color& color,
                    const std::size_t& thickness
                );

        };
        
    } // namespace Style
    

    
} // namespace re



