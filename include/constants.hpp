#ifndef MANGA_READER_CONSTANTS_HPP
#define MANGA_READER_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <filesystem>
#include "colors.hpp"
#include "util/transform.hpp"
#include <string>



namespace re {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE = "Reader";
    const sf::Color SCREEN_BG_COLOR = re::Colors::GREY_200;
    const re::Transform SCREEN_RECT({}, re::SCREEN_SIZE, {1.f, 1.f});
    const int FPS = 60;

    const int IMAGE_MOVE_SPEED = 450;

    const std::filesystem::path MANGA_DIR("/mnt/HD1/Manga");
    const std::filesystem::path MANGA_COVER_DIR("/mnt/HD1/MangaCover");
    const std::filesystem::path MANGAS_SETTINGS("res/settings/mangas_settings.txt");


    const sf::Keyboard::Key DIRECTION_KEYS[] = {
        sf::Keyboard::Up,
        sf::Keyboard::Right,
        sf::Keyboard::Left,
        sf::Keyboard::Down
    };
    
} // namespace re


#endif