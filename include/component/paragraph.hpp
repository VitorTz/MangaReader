#ifndef CA883BED_37A6_4078_840D_F96F1AF46F00
#define CA883BED_37A6_4078_840D_F96F1AF46F00
#include "component.hpp"
#include "text.hpp"


namespace re {


    class Paragraph : public re::Component {

        private:
            const std::size_t size;
            const re::FontId font;
            const sf::Color color;
            const std::size_t maxWidth;
            std::vector<std::unique_ptr<re::Text>> lines;
        
        private:
            inline void addLine(const std::string& s);
        
        public:
            Paragraph(
                const std::string& txt,
                const re::Transform& transform,
                const std::size_t& size,
                const re::FontId& font,
                const sf::Color& color,
                const std::size_t& maxWidth = 0
            );
            Paragraph(
                const std::string& txt,
                const re::Transform& transform,
                const re::style::TextStyle& style,
                const std::size_t& maxWidth
            );
            void changeTxt(const std::string& s);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* CA883BED_37A6_4078_840D_F96F1AF46F00 */
