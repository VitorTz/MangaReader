#ifndef MANGA_READER_CONSTANTS_HPP
#define MANGA_READER_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <filesystem>
#include <string>
#include <map>
#include "util/transform.hpp"
#include "colors.hpp"


namespace re
{

    // window
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 650;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const sf::Color SCREEN_BG_COLOR = re::Colors::GREY_200;
    const re::Transform SCREEN_RECT({}, re::SCREEN_SIZE);
    const std::string SCREEN_TITLE = "Manga Reader";
    const int FPS = 60;

    // res
    const std::filesystem::path BOOKMARK_0_FILE = "res/images/bookmark_0.png";
    const std::filesystem::path BOOKMARK_1_FILE = "res/images/bookmark_1.png";

    // reader
    const int IMAGE_MOVE_SPEED = 450;

    // dir    
    const std::filesystem::path DEFAULT_COVER = "res/images/cover.png";
    const std::filesystem::path MANGAS_FILE("settings/mangas.json");
    const std::filesystem::path SETTINGS_FILE("settings/settings.json");

    // grid
    const sf::Vector2f GRID_ITEM_SIZE(200, 280);
    const int GRID_GAP = 5;

    // font
    enum FontId
    {
        Thin,
        Regular,
        Medium,
        Bold
    };

    const std::map<re::FontId, std::string> fontPathById = {
        {re::FontId::Thin, "res/font/Poppins-Light.ttf"},
        {re::FontId::Regular, "res/font/Poppins-Regular.ttf"},
        {re::FontId::Medium, "res/font/Poppins-Medium.ttf"},
        {re::FontId::Bold, "res/font/Poppins-Bold.ttf"}};

} // namespace re

#endif