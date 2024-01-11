#include "../../include/component/grid_item.hpp"


re::GridItem::GridItem(
    const std::shared_ptr<re::Manga> manga
) : re::Component(manga->name),
    manga(manga),
    image(manga->mangaCoverFile),
    rect({{}, re::GRID_RECT_SIZE}, re::Colors::BLACK_TRANSPARENT) {
    this->image.load();
    this->setPos({200, 200});
}


void re::GridItem::setPos(const sf::Vector2f& pos) {
    this->transform.pos = pos;
    this->image.transform.pos = pos;
    this->rect.transform.setLeft(pos.x);
    this->rect.transform.setBottom(this->image.transform.bottom());
}


void re::GridItem::draw(sf::RenderWindow& window) {
    this->image.draw(window);
    this->rect.draw(window);
}