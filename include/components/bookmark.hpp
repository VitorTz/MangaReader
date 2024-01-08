#pragma once
#include "sprite.hpp"



namespace re {

    class Bookmark {

        private:
            re::Sprite* bookmark_0;
            re::Sprite* bookmark_1;
        
        public:
            Bookmark();
            ~Bookmark();
            void draw(
                sf::RenderWindow& window, 
                const bool& status,
                const sf::Vector2f& pos
            );

    };
    
} // namespace ze
