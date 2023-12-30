#ifndef MANGA_READER_CONSTANTS_HPP
#define MANGA_READER_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <string>
#include "colors.hpp"
#include "util/rect.hpp"


namespace og {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE = "Manga Reader";
    const sf::Color SCREEN_COLOR = og::Colors::GREY_200;
    const og::Rect SCREEN_RECT(sf::Vector2f(), og::SCREEN_SIZE);
    const int FPS = 60;

    const int SPEED = 500;

    const std::string MANGA_DIR = "/mnt/HD1/Manga";
    
} // namespace og



#endif
