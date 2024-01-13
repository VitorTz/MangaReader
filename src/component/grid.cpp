#include "../../include/component/grid.hpp"


re::Grid::Grid(
    const sf::Vector2f& pos,
    const std::size_t& columns,
    const std::size_t& gap    
) : re::Component("Grid"),
    pos(pos),
    columns(columns),
    gap(gap),
    itemSize({re::GRID_ITEM_SIZE.x + gap, re::GRID_ITEM_SIZE.y + gap}),
    text(re::MANGA_DIR + " is empty", {}, 20, re::FontId::Bold, sf::Color::White),
    border({{}, re::GRID_ITEM_SIZE}, 1, re::Colors::PURPLE_200),
    currentItemIndex(0) {
    this->text.transform.setCenter(re::SCREEN_CENTER);
    
    for (const auto& [mangaName, manga] : re::globals::mangaByName)
        this->items.push_back(std::make_unique<re::GridItem>(manga));
    
    this->sortItemsByFavorite();
    this->resetPos();
}


void re::Grid::changeCurrentItem(const std::size_t& n) {
    if (n < this->items.size()) {
        this->currentItemIndex = n;
        this->resetPos();
    }
}

void re::Grid::sortItemsByFavorite() {
    std::sort(
        this->items.begin(),
        this->items.end(),
        [](std::unique_ptr<re::GridItem>& i1, std::unique_ptr<re::GridItem>& i2) {
            const auto& [i1Name, i1IsFavorite] = i1->getItemInfo();
            const auto& [i2Name, i2IsFavorite] = i2->getItemInfo();
            if (i1IsFavorite && !i2IsFavorite)
                return true;
            else if (!i1IsFavorite && i2IsFavorite)
                return false;
            return i1Name < i2Name;
        }
    );
}

void re::Grid::resetPos() {
    const float deltaY = (this->currentItemIndex / this->columns) * this->itemSize.y;
    int i = 0;
    for (std::unique_ptr<re::GridItem>& item : this->items) {  
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


std::size_t re::Grid::indexOfItem(const std::string& mangaName) {
    for (std::size_t i = 0; i < this->items.size(); i++) {
        std::unique_ptr<re::GridItem>& item = this->items.at(i);
        if (item->name == mangaName) return i;
    }
    return 0;
}

void re::Grid::favoriteCurrentItem() {
    if (!this->items.empty()) {
        const std::string& mangaName = this->items.at(this->currentItemIndex)->name;
        std::shared_ptr<re::Manga>& manga = re::globals::mangaByName.at(mangaName);
        manga->isFavorite = !manga->isFavorite;
        this->sortItemsByFavorite();
        this->currentItemIndex = this->indexOfItem(mangaName);
        this->resetPos();
        std::string r = manga->isFavorite ? "" : "not ";
        std::string msg = manga->name + " marked as " + r + "favorite";
        re::NotificationManager::showNotification(msg);
    }
}


void re::Grid::update(const float& dt) {
    for (const sf::Keyboard::Key& k : re::globals::pressedKeys) {
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
            case sf::Keyboard::F:
                this->favoriteCurrentItem();
                break;
            default:
                break;
        }
    }
}


void re::Grid::draw(sf::RenderWindow& window) {
    if (this->items.empty()) {
        this->text.draw(window);
        return;
    }

    for (std::unique_ptr<re::GridItem>& item : this->items)
        if (item->transform.collide(re::SCREEN_RECT))
            item->draw(window);
    
    if (!this->items.empty()) {
        std::unique_ptr<re::GridItem>& item = this->items.at(this->currentItemIndex);
        const std::size_t& t = this->border.getThickness();
        this->border.setThickness(4);
        this->border.transform.pos = item->transform.pos;
        this->border.draw(window);
        this->border.setThickness(t);
    }
}


std::string re::Grid::getItem() const {
    std::string r;    
    if (!this->items.empty() && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        r = this->items.at(this->currentItemIndex)->name;
    return r;
}