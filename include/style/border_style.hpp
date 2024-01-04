#ifndef MANGA_READER_BORDER_STYLE_HPP
#define MANGA_READER_BORDER_STYLE_HPP
#include <SFML/Graphics/Color.hpp>
#include <cstddef>
#include "../util/state.hpp"



namespace re {

    typedef struct BorderStyle {
        
        re::State<sf::Color> colorState;
        re::State<std::size_t> thicknessState;        

    } BorderStyle;
    
} // namespace re


#endif