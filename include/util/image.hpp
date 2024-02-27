#pragma once
#include "SFML/Graphics.hpp"
#include "../constants.hpp"
#include <filesystem>
#include "texture_pool.hpp"


namespace mr {

    typedef struct {
        std::string name;
        std::filesystem::path path;        
        sf::Sprite sprite;
        sf::Vector2f pos;
        sf::Vector2f size;
    } image;

    mr::image* image_create(const std::filesystem::path& image_file);
    void image_destroy(mr::image* image);
    void image_resize(mr::image* image, const sf::Vector2f size);
    void image_load(mr::image* image);
    void image_draw(mr::image* image, sf::RenderWindow& window);
    
} // namespace mr
