#include "../../include/style/text_style.hpp"



re::Style::TextStyle::TextStyle(
    const re::Font::FontId& font,
    const std::size_t& size,
    const sf::Color& color
) : font(font),
    size(size),
    color(color) {

}