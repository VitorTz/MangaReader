#ifndef EE648ADF_AE53_403F_9788_6A158AE29A9C
#define EE648ADF_AE53_403F_9788_6A158AE29A9C
#include "component.hpp"


namespace re {

    class Text : public re::Component {

        public:
            static sf::Vector2f strSize(const std::string& s, const std::size_t& size, const re::FontId& f);
            static sf::Vector2f strSize(const sf::Text& text);
            
        private:
            sf::Text text;

        public:
            Text(
                const std::string& txt,
                const re::Transform& transform,
                const std::size_t& size,
                const re::FontId& font,
                const sf::Color& color
            );
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* EE648ADF_AE53_403F_9788_6A158AE29A9C */
