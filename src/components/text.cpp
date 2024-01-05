#include "../../include/components/text.hpp"


re::Text::Text(
    const std::string& txt,
    const re::Style::TextStyle& style
) : re::Component(txt),
    textStr(txt) {
        sf::Font* f = re::Font::FontPool::get(style.font);
        this->text.setFont(*f);
        this->text.setFillColor(style.color);
        this->text.setCharacterSize(style.size);
        this->changeTxt(txt);
    }



void re::Text::changeTxt(const std::string& s) {
    this->text.setString(s);
    this->textStr = s;
    sf::FloatRect size = this->text.getLocalBounds();
    this->transform.setSize({size.width, size.height});
}


void re::Text::draw(sf::RenderWindow& window) {
    this->text.setPosition(this->transform.getPos());    
    window.draw(this->text);
}


void re::Text::setCenter(const sf::Vector2f& pos) {
    this->transform.setCenter({pos.x, pos.y - 10});
}