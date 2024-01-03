#ifndef MANGA_READER_WINDOW_HPP
#define MANGA_READER_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"
#include "../constants.hpp"
#include "../globals.hpp"


namespace re {


    class Window {


        private:
            sf::RenderWindow window;
            sf::Clock clock;
            re::Scene* scene;
            re::ChangeScene changeScene;
        
        private:
            void handleInput();
            void update();
            void draw();

        public:
            Window();
            ~Window();
            void run();

    };
    
} // namespace reader


#endif