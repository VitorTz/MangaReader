#pragma once
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"


namespace mr::constants  {

    // window
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(1280, 720);
    const char WINDOW_TITLE[] = "Manga Reader";
    const int FPS = 60;
    const sf::Color SCREEN_BG_COLOR(18, 18, 18);

    // res 
    const char DEFAULT_MANGA_COVER_IMAGE[] = "res/images/cover.png";
    const char MANGA_DIR[] = "/mnt/HD/Manga";
    const char FONT_PATH[] = "res/font/Poppins-Regular.ttf";

    // reader scene
    const double SCROLL_SPEED = 550.0;

    // library scene
    const sf::Vector2f GRID_ITEM_SIZE(260, 364);
    const sf::Vector2f GRID_POS(100.f, 20.f);
    const sf::Vector2f GRID_PADDING(10.f, 10.f);
    const int GRID_COLUMNS = 4;

    
} // namespace mr::constants 
