#pragma once
#include "component.hpp"


namespace re {

    class Sprite : public re::Component {

        private:
            sf::Sprite sprite;            
            
        public:
            Sprite(const std::string& imagePath);
            Sprite(
                const std::string& imagePath,
                const re::Transform& transform
            );
            ~Sprite() override;            
            void draw(sf::RenderWindow& window);

    };
    
} // namespace re

