#include "../include/grid_item.hpp"


mr::GridItem::GridItem(
    const std::string& manga_name_,
    const std::filesystem::path& cover_image,
    const sf::Vector2f pos_
) : manga_name(manga_name_) {
    
    size = mr::constants::GRID_ITEM_SIZE;    
    image = mr::image_create(cover_image);

    mr::image_load(image);    
    mr::image_resize(image, size);

    font.loadFromFile(mr::constants::FONT_PATH);
    txt.setFont(font);
    txt.setFillColor(sf::Color::White);
    txt.setCharacterSize(14);
    txt.setString(
        manga_name.size() < 30 ? manga_name : manga_name.substr(0, 30) + "..."
    );

    border.setSize(size + sf::Vector2f(4.f, 4.f));
    border.setFillColor(sf::Color::White);
    
    txt_background.setSize({size.x, 30});
    txt_background.setFillColor(sf::Color(0, 0, 0, 120));
    setPos(pos_);
}


mr::GridItem::~GridItem() {
    mr::image_destroy(image);
}


void mr::GridItem::draw_border(sf::RenderWindow& window) {
    if (on_hover) {
        window.draw(border);
    }    
}


void mr::GridItem::draw(sf::RenderWindow& window) {
    draw_border(window);
    mr::image_draw(image, window);
    window.draw(txt_background);
    window.draw(txt);
}


void mr::GridItem::setPos(const sf::Vector2f pos) {
    this->pos = pos;
    image->pos = pos;    
    border.setPosition(pos - sf::Vector2f(2.f, 2.f));
    txt_background.setPosition({pos.x, image->pos.y + image->size.y - 30});
    txt.setPosition(
        {
            pos.x + 5,
            image->pos.y + image->size.y - 20
        }
    );
}

const sf::Vector2f& mr::GridItem::getPos() const {
    return pos;
}


void mr::GridItem::set_on_hover(const bool on_hover_) {
    on_hover = on_hover_;
} 


const std::string& mr::GridItem::get_manga_name() const {
    return manga_name;
}


const sf::Vector2f& mr::GridItem::getSize() const {
    return size;
}