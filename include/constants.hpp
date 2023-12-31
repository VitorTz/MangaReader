#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include "util/transform.hpp"
#include "colors.hpp"


namespace re {


    namespace constants {
        
        const int SCR_WIDTH = 1280;
        const int SCR_HEIGHT = 720;
        const sf::Vector2f SCR_SIZE(SCR_WIDTH, SCR_HEIGHT);
        const sf::Vector2f SCR_CENTER(SCR_WIDTH / 2, SCR_HEIGHT / 2);
        const re::Transform SCR_TRANSFORM({}, SCR_SIZE);
        const std::string SCR_TITLE("Manga Reader");
        const sf::Color SCR_COLOR = re::Colors::DARK_BLUE;
        
        const int FPS = 60;
        const int IMAGE_MOVE_SPEED = 450;

        const std::string MANGA_DIR = "/mnt/HD1/Manga";
        const std::string MANGA_COVER_DIR = "/mnt/HD1/MangaCover";
        const std::string DEFAULT_COVER_FILE = "res/cover.png";
        const std::string MANGA_INFO_FILE = "res/mangas.txt";

        const std::string BOOKMARK_ICON_0 = "res/bookmark_0.png";
        const std::string BOOKMARK_ICON_1 = "res/bookmark_1.png";

        const sf::Vector2f GRID_ITEM_SIZE(240, 336);
        const sf::Vector2f GRID_ITEM_RECT_SIZE(240, 100);
        const sf::Color GRID_ITEM_RECT_COLOR = re::Colors::BLACK_TRANSPARENT;

        const sf::Keyboard::Key INTERACTION_KEYS[] = {
            sf::Keyboard::Key::Left,
            sf::Keyboard::Key::Right,
            sf::Keyboard::Key::Up,
            sf::Keyboard::Key::Down,
            sf::Keyboard::Key::F,
            sf::Keyboard::Key::R
        };

    } // namespace constants
    
    
} // namespace re

