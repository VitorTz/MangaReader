#pragma once
#include <SFML/Graphics/Color.hpp>
#include <filesystem>
#include <map>
#include "util/font_id.hpp"


namespace mr::constants {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const int FPS = 60;
    const char WINDOW_TITLE[] = "Manga Reader";
    const sf::Color WINDOW_BG_COLOR(18, 18, 18);

    const double SCROLL_SPEED = 550.0;

    // res
    const std::filesystem::path DEFAULT_COVER_IMAGE("res/images/cover.png");
    const std::filesystem::path MANGA_DIR("/home/vitor/Manga");

    const std::map<mr::FontId, std::filesystem::path> FONT_PATH = {
        {mr::FontId::Light, "res/font/Poppins-Light.ttf"},
        {mr::FontId::Regular, "res/font/Poppins-Regular.ttf"},
        {mr::FontId::SemiBold, "res/font/Poppins-SemiBold.ttf"},
        {mr::FontId::Bold, "res/font/Poppins-Bold.ttf"}
    };

}