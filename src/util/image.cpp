#include "../../include/util/image.hpp"


std::mutex mr::Image::m;
std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> mr::Image::texture_map;


mr::Image::Image(
    const std::filesystem::path& path
) : path(path),
    name(path.stem().string()) { }


mr::Image::~Image() {
    if (texture_map.find(path) != texture_map.end()) {
        texture_map.erase(path);
        std::cout << "[IMAGE UNLOAD] [" << path << "]\n";
    }
}


void mr::Image::load() {
    if (texture_map.find(path) == texture_map.end()) {
        m.lock();
        const auto& [pair, success] = texture_map.insert(
            {
                path,
                std::make_unique<sf::Texture>()
            }
        );
        m.unlock();
        pair->second->setSmooth(true);
        pair->second->loadFromFile(path);
        std::cout << "[IMAGE LOAD] [" << path << "]\n";
    }
    sf::Texture* t = texture_map.at(path).get();    
    sprite.setTexture(*t);
    size = (sf::Vector2f) t->getSize();
}


void mr::Image::fit_on_screen() {
    if (size.x > mr::constants::SCREEN_WIDTH) {
        const float d = mr::constants::SCREEN_WIDTH / size.x;
        size.x *= d;
        size.y *= d;
        sprite.setScale({d, d});
    }
}


void mr::Image::center_on_screen() {
    pos.x = mr::constants::SCREEN_WIDTH / 2.f - size.x / 2.f;
    pos.y = mr::constants::SCREEN_HEIGHT / 2.f - size.y / 2.f;
}


void mr::Image::draw(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    window.draw(sprite);
}


const std::string& mr::Image::getName() const {
    return name;
}


void mr::draw_border(
    mr::Image *image, 
    const mr::style::border_t &border,
    sf::RenderWindow& window
) {
    mr::draw_border(image->pos, image->size, border, window);    
}


void mr::draw_border(
    sf::Vector2f pos, 
    sf::Vector2f size, 
    const mr::style::border_t& border,
    sf::RenderWindow& window
) {
    sf::RectangleShape b;
    const float thickness = border.thickness;
    
    b.setFillColor(border.color);
    b.setSize({size.x, thickness});
    b.setPosition({pos.x, pos.y});
    window.draw(b);

    b.setPosition({pos.x, pos.y + size.y});
    window.draw(b);

    b.setSize({thickness, size.y + thickness});
    b.setPosition({pos.x, pos.y});
    window.draw(b);

    b.setPosition({pos.x + size.x, pos.y});
    window.draw(b);
}
