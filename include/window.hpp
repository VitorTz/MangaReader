#pragma once
#include "SFML/Graphics.hpp"
#include "scene.hpp"
#include "constants.hpp"
#include <memory>



namespace mr {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            mr::ChangeScene changeScene;
            std::unique_ptr<mr::Scene> scene;
        
        private:
            void handle_input();
            void update();
            void render();
        
        public:
            Window();
            void run();

    };
    
} // namespace mr
