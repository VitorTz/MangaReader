#include "../../include/components/manga_cover.hpp"
#include <iostream>



re::MangaCover::MangaCover(re::Manga* manga) : re::Component(manga->name + "-Cover"),
    manga(manga),
    rect(new re::Rect(re::Colors::BLACK_200)),
    border(new re::Border(this->transform, re::Style::M_COVER)),
    sprite(new re::Sprite(manga->coverImagePath)),
    state(re::StateId::Inactive) {
        this->transform.size = this->sprite->transform.size;
        this->rect->transform.size = {
            this->transform.size.x,
            100
        };        
    }

re::MangaCover::~MangaCover() {
    for (re::Text* t : this->text)
        delete t;    
    delete this->rect;
    delete this->border;
    delete this->sprite;
}


void re::MangaCover::setUpText() {
    const std::string& mangaName = manga->name;
    
    const sf::Vector2f totalSize = re::stringSize(mangaName, 18, re::FontId::Regular);
    const std::size_t lines = std::round(0.5 + (totalSize.x / (this->transform.width() - 10)));
    
    if (lines == 1) {
        re::Text*t = new re::Text(mangaName, re::FontId::Regular, sf::Color::White, 18);
        this->text.push_back(t);
        this->rect->transform.setHeight(
            totalSize.y + 40
        );
        this->rect->transform.setBottom(this->transform.bottom());
        t->setCenter(this->rect->transform.center());
        return;
    }

    const std::size_t totalChar = mangaName.size();
    const std::size_t charPerLine = totalChar / lines;    
    std::size_t totalHeight = 0;

    
    for (std::size_t i = 0; i < totalChar; i += charPerLine) {
        std::size_t end = i + charPerLine;
        if (end > totalChar) end = totalChar;        
        re::Text* txt = new re::Text(
            re::subStr(mangaName, i, end),
            re::FontId::Regular,
            sf::Color::White,
            18
        );
        totalHeight += txt->transform.height() + 10;
        this->text.push_back(txt);
    }

    this->rect->transform.setHeight(
        totalHeight + 20
    );
    this->rect->transform.setBottom(this->transform.bottom());

    float top = this->rect->transform.top() + 10;
    re::Text* lastTxt = nullptr;
    for (re::Text* txt : this->text) {
        txt->setCenter(this->rect->transform.center());
        txt->transform.setTop(top);
        top += txt->transform.height() + 10;
        if (lastTxt) {
            const std::string& s = lastTxt->getTxt();
            const std::size_t sSize = s.size();
            if (s.at(sSize-2) == ' ') {
                txt->changeTxt(s.back() + txt->getTxt());
                lastTxt->changeTxt(re::subStr(s, 0, sSize-1));
            }
        }
        lastTxt = txt;
    }


}


void re::MangaCover::setPos(const sf::Vector2f& pos) {
    this->transform.pos = pos;
    this->sprite->transform.pos = pos;
    this->rect->transform.setLeft(this->transform.left());
    this->rect->transform.setBottom(this->transform.bottom());
    this->setUpText();
}


void re::MangaCover::draw(sf::RenderWindow& window) {
    this->sprite->draw(window);
    this->rect->draw(window);
    for (re::Text* t : this->text)
        t->draw(window);
    this->border->draw(window);
}


void re::MangaCover::moveY(const double& y) {
    this->transform.moveY(y);
    this->sprite->transform.moveY(y);
    this->rect->transform.moveY(y);
    for (re::Text* t : this->text)
        t->transform.moveY(y);
}


void re::MangaCover::setState(const re::StateId& state) {
    this->state = state;
    this->border->setStatus(state);
}


re::Manga* re::MangaCover::getManga() {
    return this->manga;
}