#pragma once
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"


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
    
} // namespace re

