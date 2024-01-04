#ifndef MANGA_READER_BORDER_HPP
#define MANGA_READER_BORDER_HPP
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../util/transform.hpp"
#include "../style/border_style.hpp"
#include "../util/state.hpp"


namespace re {


    class Border {

        private:
            const re::Transform& transform;
            const re::BorderStyle& style;
            sf::RectangleShape rect;
            re::StateId state;

        public:
            Border(
                const re::Transform& transform,
                const re::BorderStyle& style
            );            
            void setStatus(const re::StateId& status);            
            void draw(sf::RenderWindow& window);

            
    };
    
} // namespace re



#endif