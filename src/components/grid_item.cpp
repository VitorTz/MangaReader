#include "../../include/components/grid_item.hpp"
#include <iostream>



re::GridItem::GridItem(
    re::Manga* manga
) : re::Component("GridItem-" + manga->name),
    manga(manga) {
    this->image = new re::Sprite(manga->coverImagePath);    
    this->transform.setSize(this->image->transform.getSize());
    this->rect = new re::Rect(
        {{}, re::constants::GRID_ITEM_RECT_SIZE}, 
        re::constants::GRID_ITEM_RECT_COLOR
    );
    this->initTxt();
}


re::GridItem::~GridItem() {
    delete this->image;
    delete this->rect;
}


void re::GridItem::initTxt() {
    const std::string& mangaName = "Secret Class";
    const std::size_t characterSize = 18;
    const re::Font::FontId font = re::Font::FontId::Regular;

    sf::Vector2f txtSize = re::Font::getStrSize(mangaName, characterSize, font);
    const int lines = std::round((0.5 + (txtSize.x / this->rect->transform.width())));
    std::cout << lines << '\n';
}


void re::GridItem::setPos(const sf::Vector2f& pos) {
    this->image->transform.setPos(pos);
    this->transform.setPos(pos);
    this->rect->transform.setBottom(this->transform.bottom());
    this->rect->transform.setLeft(this->transform.left());
    // this->texts.at(0)->setCenter(this->rect->transform.center());
}


void re::GridItem::draw(sf::RenderWindow& window) {
    this->image->draw(window);
    this->rect->draw(window);
    for (re::Text* t : this->texts)
        t->draw(window);
}