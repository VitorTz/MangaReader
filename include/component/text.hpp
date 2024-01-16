#ifndef EE648ADF_AE53_403F_9788_6A158AE29A9C
#define EE648ADF_AE53_403F_9788_6A158AE29A9C
#include <cmath>
#include "component.hpp"
#include "../style/style.hpp"
#include "../util/font_pool.hpp"


namespace re {

    class Text : public re::Component {

        public:
            static sf::Vector2f strSize(const std::string& s, const std::size_t& size, const re::FontId& f);
            static sf::Vector2f strSize(const std::string& s, const re::style::TextStyle& style);
            
        private:
            sf::Text text;

        public:
            Text(
                const std::string& txt,
                const re::Transform& transform,
                const re::style::TextStyle& style
            );
            Text(
                const std::string& txt,
                const re::style::TextStyle& style
            );
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* EE648ADF_AE53_403F_9788_6A158AE29A9C */
