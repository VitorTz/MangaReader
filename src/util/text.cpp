#include "../../include/util/text.hpp"


std::map<mr::FontId, std::unique_ptr<sf::Font>> mr::Text::font_map;


mr::Text::Text(
    std::string txt,
    const mr::style::txt_style_t& style
) : txt_str(txt) {
    if (font_map.find(style.font) == font_map.end()) {
        const auto& [pair, success] = font_map.insert({style.font, std::make_unique<sf::Font>()});
        pair->second->loadFromFile(mr::constants::FONT_PATH.at(style.font));
    }
    text.setFont(*font_map.at(style.font).get());
    text.setFillColor(style.color);
    text.setCharacterSize(style.size);
    text.setString(txt_str);
    sf::FloatRect local_bounds = text.getLocalBounds();
    size = {local_bounds.width, local_bounds.height};
}


const std::string& mr::Text::getTxt() const {
    return txt_str;
}


void mr::Text::setTxt(const std::string& txt) {
    txt_str = txt;
    text.setString(txt_str);
    sf::FloatRect local_bounds = text.getLocalBounds();
    size = {local_bounds.width, local_bounds.height};
}


void mr::Text::draw(sf::RenderWindow& window) {
    text.setPosition(pos);
    window.draw(text);
}


void mr::Text::center_on_screen() {
    pos.x = mr::constants::SCREEN_WIDTH / 2.f - size.x / 2.f;
    pos.y = mr::constants::SCREEN_HEIGHT / 2.f - size.y / 2.f;
}


void mr::Text::setBottom(const float b) {
    pos.y = b - size.y;
}

void mr::Text::setLeft(const float l) {
    pos.x = l;
}