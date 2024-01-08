#include "../../include/components/bookmark.hpp"


re::Bookmark::Bookmark() {
    this->bookmark_0 = new re::Sprite(re::constants::BOOKMARK_ICON_0);
    this->bookmark_1 = new re::Sprite(re::constants::BOOKMARK_ICON_1);
}


re::Bookmark::~Bookmark() {
    delete this->bookmark_0;
    delete this->bookmark_1;
}


void re::Bookmark::draw(
    sf::RenderWindow& window,
    const bool& status,
    const sf::Vector2f& pos
) {
    re::Sprite* s = status == true ? this->bookmark_1 : this->bookmark_0;
    s->transform.setPos(pos);
    s->draw(window);
}