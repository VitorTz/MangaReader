#include "../../include/component/grid.hpp"
#include <iostream>

re::Grid::Grid(
    const sf::Vector2f& pos,
    const std::size_t& columns,
    const std::size_t& gap    
) : re::Component("Grid"),
    pos(pos),
    columns(columns),
    gap(gap),
    itemSize({re::GRID_ITEM_SIZE.x + gap, re::GRID_ITEM_SIZE.y + gap}),    
    border({{}, re::GRID_ITEM_SIZE}, 1, re::Colors::PINK_200),
    currentItemIndex(0) {
    for (const auto& [name, manga] : re::mangaMap)
        this->items.push_back(std::make_unique<re::GridItem>(manga));
    
    this->resetPos();
}


void re::Grid::changeCurrentItem(const std::size_t& n) {
    if (n < this->items.size()) {
        this->currentItemIndex = n;
        this->resetPos();
    }
}


void re::Grid::resetPos() {
    const float deltaY = (this->currentItemIndex / this->columns) * this->itemSize.y;
    int i = 0;
    for (auto& item : this->items) {        
        const int row = i / this->columns;
        const int col = i % this->columns;        
        item->setPos(
            {
                this->pos.x + col * this->itemSize.x,
                this->pos.y + row * this->itemSize.y - deltaY
            }
        );        
        i++;
    }
}


void re::Grid::update(const float& dt) {
    for (const sf::Keyboard::Key& k : re::pressedKeys) {
        switch (k) {
            case sf::Keyboard::Left:
                this->changeCurrentItem(this->currentItemIndex - 1);
                break;
            case sf::Keyboard::Right:
                this->changeCurrentItem(this->currentItemIndex + 1);
                break;
            case sf::Keyboard::Down:
                this->changeCurrentItem(this->currentItemIndex + this->columns);
                break;
            case sf::Keyboard::Up:
                this->changeCurrentItem(this->currentItemIndex - this->columns);
                break;
            default:
                break;
        }
    }
}


void re::Grid::draw(sf::RenderWindow& window) {
    for (auto& item : this->items) {
        if (item->transform.collide(re::SCREEN_RECT))
            item->draw(window);
    }
    if (!this->items.empty()) {
        auto& item = this->items.at(this->currentItemIndex);
        const std::size_t t = this->border.getThickness();
        this->border.setThickness(3);
        this->border.transform.pos = item->transform.pos;
        this->border.draw(window);
        this->border.setThickness(t);
    }
}


re::Item re::Grid::getItem() const {
    if (!this->items.empty()) {
        return {
            this->items.at(this->currentItemIndex)->name, 
            sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)
        };
    }
    return {"", false};
}