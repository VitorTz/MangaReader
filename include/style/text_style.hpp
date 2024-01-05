#pragma once
#include <SFML/Graphics/Color.hpp>
#include "../util/font_pool.hpp"


namespace re {

    namespace Style {

        class TextStyle {

            public:
                const re::Font::FontId font;
                const std::size_t size;
                const sf::Color color;
            
            TextStyle(
                const re::Font::FontId& font,
                const std::size_t& size,
                const sf::Color& color
            );

        };
        
    } // namespace Style
    
    
} // namespace re
