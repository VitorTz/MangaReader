#ifndef CA883BED_37A6_4078_840D_F96F1AF46F00
#define CA883BED_37A6_4078_840D_F96F1AF46F00
#include "component.hpp"
#include "text.hpp"


namespace re {


    class Paragraph : public re::Component {

        private:
            std::vector<std::unique_ptr<re::Text>> lines;
        
        public:
            Paragraph(
                const std::string& txt,
                const re::Transform& transform,
                const std::size_t& size,
                const re::FontId& font,
                const sf::Color& color,
                const std::size_t& maxWidth = 0
            );
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* CA883BED_37A6_4078_840D_F96F1AF46F00 */
