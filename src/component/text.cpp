#include "../../include/component/text.hpp"


re::Text::Text(
    const std::string& txt,
    const re::Transform& transform,
    const std::size_t& size,
    const re::FontId& font,
    const sf::Color& color    
) : re::Component(txt, transform) {
        this->text.setFillColor(color);
        this->text.setCharacterSize(size);
        this->text.setString(txt);
        re::FontPool::load(this->text, font);
        this->transform.size = re::Text::strSize(this->text);
    }


sf::Vector2f re::Text::strSize(
    const sf::Text& text 
) {
    const sf::FloatRect r = text.getLocalBounds();
    return {r.width, r.height};
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
    return re::Text::strSize(t);
}


void re::Text::draw(sf::RenderWindow& window) {
    this->text.setPosition(this->transform.pos);
    window.draw(this->text);
}