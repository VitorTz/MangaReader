#include "../../include/component/paragraph.hpp"


re::Paragraph::Paragraph(
    const std::string& txt,
    const re::Transform& transform,
    const std::size_t& size,
    const re::FontId& font,
    const sf::Color& color,
    const std::size_t& maxWidth
) : re::Component("Paragraph", transform),
    size(size),
    font(font),
    color(color),
    maxWidth(maxWidth) {
    this->changeTxt(txt);
}


void re::Paragraph::changeTxt(const std::string& txt) {
    this->lines.clear();
    const std::size_t txtLenght = txt.size();
    const sf::Vector2f txtDimension = re::Text::strSize(txt, this->size, this->font);
    const std::size_t lines = this->maxWidth == 0 ? 1 : std::round(txtDimension.x / this->maxWidth + 0.5);
    const std::size_t charPerLine = txtLenght / lines;
    
    std::vector<std::string> words = re::split(txt, ' ');
    std::string currentLine;
    for (const std::string& word : words) {
        if (currentLine.size() + word.size() <= charPerLine+1) {
            currentLine += word;
            currentLine += ' ';
        } else {
            this->lines.push_back(
                std::make_unique<re::Text>(currentLine, re::Transform(), this->size, this->font, this->color)
            );
            currentLine = word;
            currentLine += ' ';
        }
    }
    if (!currentLine.empty()) {
        this->lines.push_back(
            std::make_unique<re::Text>(currentLine, re::Transform(), this->size, this->font, this->color)
        );
    };
    this->transform.size.x = 0;
    for (std::unique_ptr<re::Text>& line : this->lines) {
        this->transform.setHeight(this->transform.height() + line->transform.height() + 10);
        const float w = line->transform.width();
        if (w > this->transform.size.x) 
            this->transform.size.x = w;
    }
}


void re::Paragraph::draw(sf::RenderWindow& window) {
    sf::Vector2f p = this->transform.pos;
    for (auto& line : this->lines) {
        line->transform.setCenterX(this->transform.centerX());
        line->transform.setTop(p.y);
        p.y += line->transform.height() + 10;
        line->draw(window);
    }
}