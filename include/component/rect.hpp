#ifndef DE528133_7112_4EC3_9DF7_1644BFBC6366
#define DE528133_7112_4EC3_9DF7_1644BFBC6366
#include "component.hpp"


namespace re {


    class Rect : public re::Component {

        private:
            sf::RectangleShape rect;

        public:
            Rect(
                const re::Transform& transform,
                const sf::Color& color
            );
            void changeColor(const sf::Color& color);
            void draw(sf::RenderWindow& window) override;

    };

    
} // namespace re


#endif /* DE528133_7112_4EC3_9DF7_1644BFBC6366 */
