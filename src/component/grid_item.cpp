#include "../../include/component/grid_item.hpp"


re::Bookmark::Bookmark(

) : b0(re::BOOKMARK_0_FILE),
    b1(re::BOOKMARK_1_FILE) {
        this->b0.load();
        this->b1.load();
    }


void re::Bookmark::draw(
    sf::RenderWindow& window,
    const re::Transform& t,
    const bool& isFavorite
) {
    re::Sprite& s = isFavorite ? this->b1 : this->b0;
    s.transform.setRight(t.right() - 10);
    s.transform.setTop(t.top() + 10);
    s.draw(window);
}



re::Bookmark re::GridItem::bookmark;


re::GridItem::GridItem(
    const std::shared_ptr<re::Manga> manga
) : re::Component(manga->name, {{}, {re::GRID_ITEM_SIZE}}),
    manga(manga),
    image(manga->mangaCoverFile),
    text(manga->name, {}, re::style::gridItemTxtStyle, re::GRID_ITEM_SIZE.x - 10),
    rect({{}, {re::GRID_ITEM_SIZE.x, text.transform.height() + 10}}, re::Colors::BLACK_TRANSPARENT) {
    this->image.load();
}


void re::GridItem::setPos(const sf::Vector2f& pos) {
    this->transform.pos = pos;
    this->image.transform.pos = pos;
    this->text.transform.setLeft(this->transform.left() + 5);
    this->text.transform.setBottom(this->transform.bottom() - 5);
    this->rect.transform.setLeft(pos.x);
    this->rect.transform.setBottom(this->image.transform.bottom());
}


void re::GridItem::draw(sf::RenderWindow& window) {
    this->image.draw(window);
    this->rect.draw(window);
    this->text.draw(window);
    re::GridItem::bookmark.draw(window, this->transform, this->manga->isFavorite);
}


const std::shared_ptr<re::Manga>& re::GridItem::getManga() {
    return this->manga;
}

