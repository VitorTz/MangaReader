#include "../../include/component/grid_item.hpp"


re::GridItem::GridItem(
    const std::shared_ptr<re::Manga> manga
) : re::Component(manga->name, {{}, {re::GRID_ITEM_SIZE}}),
    manga(manga),
    image(manga->mangaCoverFile),
    text(manga->name, {}, 18, re::FontId::Medium, sf::Color::White, re::GRID_RECT_SIZE.x),
    rect({{}, {re::GRID_RECT_SIZE.x, text.transform.height() + 20}}, re::Colors::BLACK_TRANSPARENT) {
    this->image.load();
    this->setPos({200, 200});
}


void re::GridItem::setPos(const sf::Vector2f& pos) {
    this->transform.pos = pos;
    this->image.transform.pos = pos;
    this->text.transform.setCenterX(this->transform.centerX());
    this->text.transform.setBottom(this->transform.bottom() - 10);
    this->rect.transform.setLeft(pos.x);
    this->rect.transform.setBottom(this->image.transform.bottom());
}


void re::GridItem::draw(sf::RenderWindow& window) {
    this->image.draw(window);
    this->rect.draw(window);
    this->text.draw(window);
}