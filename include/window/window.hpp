#ifndef MANGA_READER_WINDOW_HPP
#define MANGA_READER_WINDOW_HPP
#include <fstream>
#include <iostream>
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
            void initWindow();
            void initGlobals();
            void deleteGlobals();
            void close();

        public:
            Window();
            ~Window();
            void run();

    };
    
} // namespace reader


#endif