#ifndef MANGA_READER_WINDOW_HPP
#define MANGA_READER_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"
#include "../constants.hpp"


namespace og {

    class Window {


        private:
            sf::RenderWindow window;
            sf::Clock clock;
            og::Scene* scene;
            og::ChangeScene changeScene;
        
        private:
            void handleInput();
            void update();
            void draw();
        
        public:
            Window();
            ~Window();
            void run();

    };
    
} // namespace og


#endif