#include "../../include/style/style.hpp"


re::Style::BorderStyle::BorderStyle(
    const sf::Color& color,
    const std::size_t& thickness
) : color(color),
    thickness(thickness) {

    }


re::Style::TextStyle::TextStyle(
    const re::Font::FontId& font,
    const std::size_t& size,
    const sf::Color& color
) : font(font),
    size(size),
    color(color) {

}