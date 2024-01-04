#pragma once
#include "component.hpp"


namespace re {

    class Text : public re::Component {


        private:
            std::string textStr;
            sf::Text text;

        public:
            Text(
                const std::string& txt,
                const std::size_t& size,
                const re::Font::FontId& fontId,
                const sf::Color& color
            ); 
            void changeTxt(const std::string& s);           
            void setCenter(const sf::Vector2f& center);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re
