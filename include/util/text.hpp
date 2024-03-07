#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include "style.hpp"
#include "../constants.hpp"


namespace mr {


    class Text {

        private:
            static std::map<mr::FontId, std::unique_ptr<sf::Font>> font_map;

        private:
            std::string txt_str;
            sf::Text text;
            sf::Font font;
        public:
            sf::Vector2f pos;
            sf::Vector2f size;

        public:
            Text(std::string txt, const mr::style::txt_style_t& style);
            const std::string& getTxt() const;
            void setTxt(const std::string& txt);
            void draw(sf::RenderWindow& window);
            void center_on_screen();
            void setBottom(float b);
            void setLeft(float l);

    };

}