#include "../../include/component/text.hpp"



re::Text::Text(
    const std::string& txt,
    const re::Transform& transform,
    const re::style::TextStyle& style
) : re::Component(txt, transform) {
    this->text.setString(txt);
    this->text.setFillColor(style.color);
    this->text.setCharacterSize(style.size);
    re::FontPool::load(this->text, style.font);
    this->transform.size = re::Text::strSize(txt, style);
}

re::Text::Text(
    const std::string& txt,
    const re::style::TextStyle& style
) : re::Text(txt, { }, style) {

}


sf::Vector2f re::Text::strSize(
    const std::string& s,
    const re::style::TextStyle& style
) {
    return re::Text::strSize(s, style.size, style.font);
}

sf::Vector2f re::Text::strSize(
    const std::string& s,
    const std::size_t& size,
    const re::FontId& f
) {
    sf::Text t;
    t.setCharacterSize(size);
    t.setString(s);
    re::FontPool::load(t, f);
    const sf::FloatRect r = t.getLocalBounds();
    return {r.width, r.height};
}


void re::Text::draw(sf::RenderWindow& window) {
    this->text.setPosition(
        {
            std::round(this->transform.pos.x),
            std::round(this->transform.pos.y)
        }
    );
    window.draw(this->text);
}