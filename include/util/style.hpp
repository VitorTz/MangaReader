#pragma once
#include <SFML/Graphics/Color.hpp>
#include <cstddef>
#include "font_id.hpp"


namespace mr::style {

    typedef struct border {
        sf::Color color;        
        std::size_t thickness;       
    } border_t;

    typedef struct txt_style {
        mr::FontId font;
        sf::Color color;
        std::size_t size;
    } txt_style_t;

    const mr::style::border_t BORDER_WHITE{sf::Color::White, 2};
    
    const mr::style::txt_style_t TXT_HEADER{mr::FontId::SemiBold, sf::Color::White, 24};
    const mr::style::txt_style_t TXT_REGULAR{mr::FontId::Regular, sf::Color::White, 18};
    const mr::style::txt_style_t TXT_Light{mr::FontId::Light, sf::Color::White, 14};
    

}
