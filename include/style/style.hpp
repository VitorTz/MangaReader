#pragma once
#include <cctype>
#include "../util/font_pool.hpp"
#include "../colors.hpp"


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

        const re::Style::TextStyle coverTxtStyle(
            re::Font::FontId::Regular,
            18,
            sf::Color::White
        );

        const re::Style::BorderStyle coverBorderStyle(
            re::Colors::PINK,
            4
        );
        
    } // namespace Style
    
    
} // namespace re
