#include "../../include/components/text.hpp"



re::Text::Text(
    const std::string& name, 
    const std::string& text,
    const re::FontId& fontId,
    const sf::Color& color,
    const std::size_t& size
) : re::Component(name),
    txtStr(text) {
        this->text.setFillColor(color);
        this->text.setCharacterSize(size);
        sf::Font* f = re::FontPool::get(fontId);
        this->text.setFont(*f);
        this->changeTxt(text);
    }


re::Text::Text(
    const std::string& text,
    const re::FontId& fontId,
    const sf::Color& color,
    const std::size_t& size
) : re::Text(
    "text",
    text,
    fontId,
    color,
    size
) {

}


void re::Text::changeTxt(const std::string& text) {
    this->txtStr = text;
    this->text.setString(text);
    const sf::FloatRect& r = this->text.getLocalBounds();
    this->transform.size = {r.width, r.height};
}


void re::Text::setCenter(const sf::Vector2f& pos) {
    this->transform.setCenter({pos.x, pos.y - 8});
}

void re::Text::draw(sf::RenderWindow& window) {
    this->text.setPosition(this->transform.pos);
    window.draw(this->text);
}


const std::string& re::Text::getTxt() const {
    return this->txtStr;
}