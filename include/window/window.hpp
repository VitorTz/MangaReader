#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.hpp"
#include "../constants.hpp"


namespace mr {

    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            mr::ChangeScene change_scene;
            std::unique_ptr<mr::Scene> scene;            
        
        private:
            void handle_input();
            void update();
            void render();

        public:
            Window();
            void run();

    };


} 