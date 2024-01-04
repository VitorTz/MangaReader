#include "../../include/components/manga_grid.hpp"


re::MangaGrid::MangaGrid(
    const sf::Vector2f& pos 
) : re::Component("MangaGrid", {pos}),
    columns(4),
    currentMangaIndex(0),
    timer(0.1) {
    for (const auto& pair : re::globals::mangaByName) {
        re::MangaCover* cover = new re::MangaCover(pair.second);
        if (cover->getManga()->isFavorite) 
            this->mangaCoverList.insert(this->mangaCoverList.begin(), cover);
        else
            this->mangaCoverList.push_back(cover);
    }
    this->mangaCoverList.at(this->currentMangaIndex)->setState(re::StateId::Active);
    this->setGridPos();
}


re::MangaGrid::~MangaGrid() {
    re::clearPtrVector(this->mangaCoverList);
}


void re::MangaGrid::draw(sf::RenderWindow& window) {
    for (re::MangaCover* cover : this->mangaCoverList)
        if (cover->transform.collide(re::SCREEN_RECT))
            cover->draw(window);
}


void re::MangaGrid::setGridPos() {

    const sf::Vector2f& pos = this->transform.pos;
    const sf::Vector2f& coverSize = this->mangaCoverList.at(0)->transform.size;
    for (std::size_t i = 0; i < this->mangaCoverList.size(); i++) {
        this->mangaCoverList.at(i)->setPos(
            {
                pos.x + (coverSize.x + 10) * (i % this->columns),
                pos.y + (coverSize.y + 10) * ((int) (i / this->columns))
            }
        );
    }

}


void re::MangaGrid::changeSelectedManga(const std::size_t& index) {
    if (index < this->mangaCoverList.size()) {
        this->mangaCoverList.at(this->currentMangaIndex)->setState(re::StateId::Inactive);
        this->currentMangaIndex = index;
        this->mangaCoverList.at(this->currentMangaIndex)->setState(re::StateId::Active);
    }
}


void re::MangaGrid::moveGridDown() {
    const float deltaY = this->mangaCoverList.at(this->currentMangaIndex)->transform.height() + 10;
    for (re::MangaCover* cover : this->mangaCoverList)
        cover->moveY(deltaY);
}



void re::MangaGrid::moveGridUp() {
    const float deltaY = -1 * (this->mangaCoverList.at(this->currentMangaIndex)->transform.height() + 10);
    for (re::MangaCover* cover : this->mangaCoverList)
        cover->moveY(deltaY);
}


void re::MangaGrid::fixPos() {
    re::MangaCover* cover = this->mangaCoverList.at(this->currentMangaIndex);
    re::Transform& t = cover->transform;
    if (t.bottom() > re::SCREEN_HEIGHT)
        this->moveGridUp();
    else if (t.top() < 0) 
        this->moveGridDown();
}

void re::MangaGrid::favoriteCurrentManga() {
    this->mangaCoverList.at(this->currentMangaIndex)->getManga()->isFavorite = true;
}


void re::MangaGrid::handleInput(const double dt) {
    for (const sf::Keyboard::Key& k : re::INTERACTION_KEYS) {
        if (sf::Keyboard::isKeyPressed(k) && this->timer.check(dt)) {
            switch (k) {
                case sf::Keyboard::Left:
                    this->changeSelectedManga(this->currentMangaIndex - 1);
                    break;
                case sf::Keyboard::Right:
                    this->changeSelectedManga(this->currentMangaIndex + 1);
                    break;
                case sf::Keyboard::Up:
                    this->changeSelectedManga(this->currentMangaIndex - this->columns);
                    break;
                case sf::Keyboard::Down:
                    this->changeSelectedManga(this->currentMangaIndex + this->columns);
                    break;
                case sf::Keyboard::F:
                    this->favoriteCurrentManga();
                    break;
                default:
                    break;
            }
        }
    }
}


void re::MangaGrid::update(const double& dt) {
    this->handleInput(dt);
    this->fixPos();
}


re::Manga* re::MangaGrid::getCurrentSelectedManga() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        return this->mangaCoverList.at(this->currentMangaIndex)->getManga();
    return nullptr;
}