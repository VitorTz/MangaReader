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

    const std::string MANGA_DIR("/mnt/HD1/Manga");
    const std::string MANGA_COVER_DIR("/mnt/HD1/MangaCover");
    const std::string DEFAULT_MANGA_COVER = "res/cover.png";
    const std::string MANGA_SETTINGS_DIR("res/settings");
    const std::string MANGAS_SETTINGS_FILE("res/settings/mangas_settings.txt");


    const sf::Keyboard::Key DIRECTION_KEYS[] = {
        sf::Keyboard::Up,
        sf::Keyboard::Right,
        sf::Keyboard::Left,
        sf::Keyboard::Down
    };

    const sf::Keyboard::Key INTERACTION_KEYS[] = {
        sf::Keyboard::Up,
        sf::Keyboard::Right,
        sf::Keyboard::Left,
        sf::Keyboard::Down,
        sf::Keyboard::F
    };

    enum class FontId {
        Regular,
        Light,
        SemiBold,
        Bold
    };

    const std::map<re::FontId, std::string> fontPathById = {
        {re::FontId::Light, "res/font/Roboto-Thin.ttf"},
        {re::FontId::Regular, "res/font/Roboto-Regular.ttf"},
        {re::FontId::SemiBold, "res/font/Roboto-Medium.ttf"},
        {re::FontId::Bold, "res/font/Roboto-Bold.ttf"}
    };
    
} // namespace re


#endif