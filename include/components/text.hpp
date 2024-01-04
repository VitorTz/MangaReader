#ifndef MANGA_READER_TEXT_HPP
#define MANGA_READER_TEXT_HPP
#include "component.hpp"


namespace re {


    class Text : public re::Component {

        private:
            sf::Text text;
            std::string txtStr;

        public:
            Text(
                const std::string& name, 
                const std::string& text,
                const re::FontId& fontId,
                const sf::Color& color,
                const std::size_t& size
            );
            Text(                
                const std::string& text,
                const re::FontId& fontId,
                const sf::Color& color,
                const std::size_t& size
            );
            void setCenter(const sf::Vector2f& pos);
            void changeTxt(const std::string& text);
            void draw(sf::RenderWindow& window) override;
            const std::string& getTxt() const;

    };
    
} // namespace re


#endif