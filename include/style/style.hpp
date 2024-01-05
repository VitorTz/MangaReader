#pragma once
#include "text_style.hpp"
#include "border_style.hpp"
#include "../colors.hpp"


namespace re {


    namespace Style {

        const re::Style::TextStyle coverTxtStyle(
            re::Font::FontId::Regular,
            18,
            sf::Color::White
        );

        const re::Style::BorderStyle coverBorderStyle(
            re::Colors::PINK,
            2
        );
        
    } // namespace Style
    
    
} // namespace re
