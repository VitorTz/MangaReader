#ifndef MANGA_READER_STYLE_HPP
#define MANGA_READER_STYLE_HPP
#include "../colors.hpp"
#include "border_style.hpp"

namespace re {

    namespace Style {
        
        const re::BorderStyle M_COVER{
            re::State<sf::Color>(re::Colors::TRANSPARENT, re::Colors::PINK_200),
            re::State<std::size_t>(0, 3)
        };

    } // namespace Style
    


    
} // namespace re


#endif

