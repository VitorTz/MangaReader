#include "../../include/util/grid_item.hpp"



mr::GridItem::GridItem(
    mr::Manga* manga
) : manga(manga),
    text(
    manga->name.size() >= 25 ? manga->name.substr(0, 25) + "..." : manga->name, 
    mr::style::TXT_REGULAR
    ), image(manga->getCoverImagePath()),
    favorite_icon_0("res/images/bookmark_0.png"),
    favorite_icon_1("res/images/bookmark_1.png") {
    text_bg.setSize({260.f, 40.f});
    text_bg.setFillColor(sf::Color(0, 0, 0, 160));                    
    favorite_icon_0.load();
    favorite_icon_1.load();
    image.load();             
    size = image.size; 
}


void mr::GridItem::setPos(const sf::Vector2f pos_) {
    pos = pos_;
    image.pos = pos;
    text_bg.setPosition({pos.x, pos.y + size.y - 40.f});
    favorite_icon_0.pos = {
        pos.x + size.x - favorite_icon_0.size.x - 10,
        pos.y + 10
    };
    favorite_icon_1.pos = {
        pos.x + size.x - favorite_icon_0.size.x - 10,
        pos.y + 10
    };
    text.setLeft(pos.x + 5.f);
    text.setBottom(pos.y + size.y - 10.f);
}


void mr::GridItem::draw(sf::RenderWindow& window) {
    image.draw(window);
    window.draw(text_bg);
    text.draw(window);
    manga->is_favorite ? favorite_icon_1.draw(window) : favorite_icon_0.draw(window);
    if (on_hover) {
        mr::draw_border(
            pos,
            size,
            mr::style::BORDER_WHITE,
            window
        );
    }
}