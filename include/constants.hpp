#ifndef MANGA_READER_CONSTANTS_HPP
#define MANGA_READER_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <string>
#include "colors.hpp"


namespace og {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE = "Ougi Manga Reader";
    const sf::Color SCREEN_COLOR = og::Colors::GREY_200;
    const int FPS = 60;
    
} // namespace og



#endif
