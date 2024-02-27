#include "../../include/util/image.hpp"
 


mr::image* mr::image_create(const std::filesystem::path& image_file) {    
    mr::image* image = new mr::image{
        image_file.stem().string(),
        image_file
    };
    return image;
}


void mr::image_destroy(mr::image* image) {
    mr::TexturePool::destroy(image->path);
    delete image;
}


void mr::image_load(mr::image* image) {
    mr::TexturePool::load(&image->sprite, image->path);
    image->size = (sf::Vector2f) image->sprite.getTexture()->getSize();    
}


void mr::image_draw(mr::image* image, sf::RenderWindow& window) {
    if (
        image->pos.y > mr::constants::SCREEN_HEIGHT || image->pos.y + image->size.y >= 0
    ) {
        image->sprite.setPosition(image->pos);
        window.draw(image->sprite);
    }
}


void mr::image_resize(mr::image* image, const sf::Vector2f size) {
    const float delta_x = size.x / image->size.x;
    const float delta_y = size.y / image->size.y;   
    image->sprite.setScale({delta_x, delta_y});
    image->size.x *= delta_x;
    image->size.y *= delta_y;

}