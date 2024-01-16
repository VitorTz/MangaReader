#include "../../include/component/paragraph.hpp"


re::Paragraph::Paragraph(
    const std::string& txt,
    const re::Transform& transform,
    const re::style::TextStyle& style,
    const std::size_t& maxWidth
) : re::Component("Paragraph", transform),
    style(style),
    maxWidth(maxWidth) { 
    this->changeTxt(txt);
}


inline void re::Paragraph::addLine(const std::string& s) {
    this->lines.push_back(
        std::make_unique<re::Text>(s, this->style)
    );
}

void re::Paragraph::changeTxt(const std::string& txt) {
    this->lines.clear();
    const std::size_t txtLenght = txt.size();
    const sf::Vector2f txtDimension = re::Text::strSize(txt, this->style.size, this->style.font);
    const std::size_t lines = this->maxWidth == 0 ? 1 : std::round(txtDimension.x / this->maxWidth + 0.5);
    const std::size_t charPerLine = txtLenght / lines;
    
    std::vector<std::string> words = re::split(txt, ' ');
    std::string currentLine;
    for (const std::string& word : words) {
        if (currentLine.size() + word.size() <= charPerLine + 1) {
            currentLine += word + " ";
        } else {
            this->addLine(currentLine);
            currentLine = word + " ";
        }
    }
    if (!currentLine.empty()) {
        this->addLine(currentLine);
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
    for (std::unique_ptr<re::Text>& line : this->lines) {
        line->transform.pos = p;        
        p.y += line->transform.height() + 10;
        line->draw(window);
    }
}