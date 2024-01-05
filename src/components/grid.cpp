#include "../../include/components/grid.hpp"



re::Grid::Grid(
    const sf::Vector2f& pos
) : re::Component("Grid"),
    pos(pos),
    border(re::Style::coverBorderStyle),
    currentGridItem(nullptr),
    currentGridIndex(0),
    timer(5) {
        std::size_t i = 0;
        for (const auto& pair : re::globals::mangaByName) {
            re::GridItem* item = new re::GridItem(pair.second);
            const float left = this->pos.x + (i % 4 * (+ 10 + item->transform.width()));
            const float top = this->pos.y + (i / 4 * (+ 10 + item->transform.height()));
            item->setPos({left, top});
            this->items.push_back(item);
            i++;
        }
        this->currentGridItem = this->items.at(0);
    }


re::Grid::~Grid() {
    re::deletePtrVector(this->items);
}


bool re::Grid::changeCurrentItem(const std::size_t& index) {
    if (index < this->items.size()) {
        this->currentGridIndex = index;
        this->currentGridItem = this->items.at(index);
        return true;
    }
    return false;
}


void re::Grid::changeToNextItem() {
    this->changeCurrentItem(this->currentGridIndex + 1);
}


void re::Grid::changeToPreviousItem() {
    this->changeCurrentItem(this->currentGridIndex - 1);
}


void re::Grid::changeToDownColumnItem() {
    bool s = this->changeCurrentItem(this->currentGridIndex + 4);
    if (s) {
        this->moveUp();
    }
}


void re::Grid::changeToUpColumnItem() {
    bool s = this->changeCurrentItem(this->currentGridIndex - 4);
    if (s) {
        this->moveDown();
    }
}


void re::Grid::moveDown() {
    const float height = this->currentGridItem->transform.height() + 10;
    for (re::GridItem* item : this->items)
        item->moveY(height);
}


void re::Grid::moveUp() {
    const float height = -1 * this->currentGridItem->transform.height() + 10;
    for (re::GridItem* item : this->items)
        item->moveY(height);
}


void re::Grid::update(const float& dt) {
    for (const sf::Keyboard::Key& k : re::constants::INTERACTION_KEYS) {
        if (sf::Keyboard::isKeyPressed(k) && this->timer.check()) {
            switch (k) {
                case sf::Keyboard::Right:
                    this->changeToNextItem();
                    break;
                case sf::Keyboard::Left:
                    this->changeToPreviousItem();
                    break;
                case sf::Keyboard::Down:
                    this->changeToDownColumnItem();  
                    break;
                case sf::Keyboard::Up:
                    this->changeToUpColumnItem();
                    break;
                default:
                    break;
            }
        }
    }
}


void re::Grid::draw(sf::RenderWindow& window) {
    for (re::GridItem* item : this->items)
        if (item->transform.collide(re::constants::SCR_TRANSFORM))
            item->draw(window);
    this->border.draw(window, this->currentGridItem->transform);
}


std::string re::Grid::getCurrentManga() {
    if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) &&
        this->currentGridItem->transform.collidePoint(re::globals::mousePos)
    ) {
        return this->currentGridItem->getMangaName();
    }
    return "";
}