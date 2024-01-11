#ifndef MANGA_READER_CONSTANTS_HPP
#define MANGA_READER_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <string>
#include "util/transform.hpp"
#include "colors.hpp"



namespace re {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const sf::Color SCREEN_BG_COLOR = re::Colors::GREY_200;
    const re::Transform SCREEN_RECT({}, re::SCREEN_SIZE);
    const std::string SCREEN_TITLE = "Manga Reader";
    const int FPS = 60;

    const int IMAGE_MOVE_SPEED = 450;

    const std::string MANGA_DIR("/home/vitor/Documents/Mangas");
    const std::string MANGA_COVER_DIR("/home/vitor/Documents/MangaCover");
    const std::string DEFAULT_MANGA_COVER = "res/cover.png";
    const std::string MANGA_SETTINGS_DIR("settings");
    const std::string MANGAS_SETTINGS_FILE("settings/mangas_settings.txt");


    const sf::Vector2f GRID_ITEM_SIZE(240, 336);
    const sf::Vector2f GRID_RECT_SIZE(240, 100);

    
} // namespace re


#endif