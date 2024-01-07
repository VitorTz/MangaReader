#include "../../include/components/grid.hpp"
#include <iostream>


re::Grid::Grid(
    const sf::Vector2f& pos,
    const std::size_t& columns,
    const std::size_t& gap
) : re::Component("Grid"),
    pos(pos),
    columns(columns),
    gap(gap),
    border(re::Style::coverBorderStyle),
    currentItem({nullptr, 0, 0}),
    timer(5) {
        for (const auto& pair : re::globals::mangaByName)
            this->items.push_back(new re::GridItem(pair.second));
        this->sortItemsByFavorite();
        this->resetPos();
        this->currentItem.item = this->items.at(0);
    }


re::Grid::~Grid() {
    re::deletePtrVector(this->items);
}


void re::Grid::sortItemsByFavorite() {
    std::sort(
        this->items.begin(), 
        this->items.end(),
        [](re::GridItem* item1, re::GridItem* item2) {
            const bool i1 = item1->getManga()->isFavorite;
            const bool i2 = item2->getManga()->isFavorite;
            if (!i2 && i1) return true;
            if (i2 && !i1) return false;
            return item1->name < item2->name;
        }
    );
}


void re::Grid::resetPos() {
    sf::Vector2f itemSize = re::constants::GRID_ITEM_SIZE;
    itemSize.x += this->gap;
    itemSize.y += this->gap;
    for (std::size_t i = 0; i < this->items.size(); i++) {
        const std::size_t row = i / this->columns;
        const std::size_t col = i % this->columns;
        re::GridItem* item = this->items.at(i);
        item->setPos(
            {
                this->pos.x + col * itemSize.x,
                (this->pos.y + row * itemSize.y) - (this->currentItem.line * itemSize.y)
            }
        );
    }
}


void re::Grid::deleteManga() {
    re::Manga* manga = this->currentItem.item->getManga();
    re::globals::deleteManga(manga);
    this->items.erase(this->items.begin() + this->currentItem.index);
    this->currentItem.index = 0;
    this->currentItem.line = 0;
    this->currentItem.item = this->items.empty() ? nullptr : this->items.at(0);
    this->sortItemsByFavorite();
    this->resetPos();
}


void re::Grid::favoriteManga() {
    re::Manga* manga = this->currentItem.item->getManga();
    manga->isFavorite = !manga->isFavorite;
    this->sortItemsByFavorite();
    this->currentItem.item = this->items.at(0);
    this->currentItem.index = 0;
    this->currentItem.line = 0;
    this->resetPos();
}


void re::Grid::changeCurrentItem(const std::size_t& index) {
    if (index < this->items.size()) {
        this->currentItem.item = this->items.at(index);
        this->currentItem.index = index;
        const std::size_t line = index / this->columns;
        if (line != this->currentItem.line) {
            this->currentItem.line = line;
            this->resetPos();        
        }
    }
}


void re::Grid::update(const float& dt) {
    for (const sf::Keyboard::Key& k : re::constants::INTERACTION_KEYS) {
        if (!(sf::Keyboard::isKeyPressed(k) && this->timer.check()))
            continue;;
        switch (k) {
            case sf::Keyboard::Right:
                this->changeCurrentItem(this->currentItem.index + 1);
                break;
            case sf::Keyboard::Left:
                this->changeCurrentItem(this->currentItem.index - 1);
                break;
            case sf::Keyboard::Down:
                this->changeCurrentItem(this->currentItem.index + this->columns);
                break;
            case sf::Keyboard::Up:
                this->changeCurrentItem(this->currentItem.index - this->columns);
                break;
            case sf::Keyboard::F:
                this->favoriteManga();
                break;
            case sf::Keyboard::R:
                this->deleteManga();
                break;
            default:
                break;
        }
    }
}


void re::Grid::draw(sf::RenderWindow& window) {
    for (re::GridItem* item : this->items)
        if (item->transform.collide(re::constants::SCR_TRANSFORM))
            item->draw(window);
    this->border.draw(window, this->currentItem.item->transform);
}


std::string re::Grid::getCurrentManga() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        return this->currentItem.item->name;
    return "";
}

