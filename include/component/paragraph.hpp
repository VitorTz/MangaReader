#ifndef CA883BED_37A6_4078_840D_F96F1AF46F00
#define CA883BED_37A6_4078_840D_F96F1AF46F00
#include "component.hpp"
#include "text.hpp"
#include "../util/util.hpp"
#include <vector>


namespace re {


    class Paragraph : public re::Component {

        private:
            const re::style::TextStyle style;
            const std::size_t maxWidth;
            std::vector<std::unique_ptr<re::Text>> lines;
        
        private:
            inline void addLine(const std::string& s);
        
        public:
            Paragraph(
                const std::string& txt,
                const re::Transform& transform,
                const re::style::TextStyle& style,
                const std::size_t& maxWidth = 0
            );
            void changeTxt(const std::string& s);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* CA883BED_37A6_4078_840D_F96F1AF46F00 */
