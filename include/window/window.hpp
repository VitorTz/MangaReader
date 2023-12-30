#ifndef MANGA_READER_WINDOW_HPP
#define MANGA_READER_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"


namespace og {

    class Window {


        private:
            sf::RenderWindow window;
            sf::Clock clock;
            og::ChangeScene changeScene;
            og::Scene* scene;
        
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