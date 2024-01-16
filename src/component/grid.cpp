#include "../../include/component/grid.hpp"


re::Grid::Grid( 
) : re::Component("Grid"),
    itemSize({re::GRID_ITEM_SIZE.x + re::GRID_GAP, re::GRID_ITEM_SIZE.y + re::GRID_GAP}),
    text("Mangas folder is empty", re::style::headerTxtStyle),
    border(re::GRID_ITEM_SIZE, 3, sf::Color::White),
    currentItemIndex(0) {
    this->columns = re::SCREEN_WIDTH / this->itemSize.x;
    this->pos.x = (re::SCREEN_WIDTH - (this->columns * this->itemSize.x - re::GRID_GAP)) / 2;
    this->pos.y = 20;
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
            const std::shared_ptr<re::Manga>& m1 = i1->getManga();
            const std::shared_ptr<re::Manga>& m2 = i2->getManga();
            if (m1->isFavorite && !m2->isFavorite)
                return true;
            else if (!m1->isFavorite && m2->isFavorite)
                return false;
            return m1->name < m2->name;
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
        manga->changeFavoriteStatus();
        this->sortItemsByFavorite();
        this->currentItemIndex = this->indexOfItem(mangaName);
        this->resetPos();
        std::string r = manga->isFavorite ? "" : "not ";
        std::string msg = manga->name + " marked as " + r + "favorite";
        re::NotificationManager::showNotification(msg);
    }
}


void re::Grid::update([[maybe_unused]] const float dt) {
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
    
    std::unique_ptr<re::GridItem>& item = this->items.at(this->currentItemIndex);
    this->border.draw(window, item->transform.pos);
    
}


std::string re::Grid::getSelectedManga() const {
    std::string r;    
    if (!this->items.empty() && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        r = this->items.at(this->currentItemIndex)->name;
    return r;
}