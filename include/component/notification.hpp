#ifndef C880F86C_6BD1_4324_AD53_5AA0D974A676
#define C880F86C_6BD1_4324_AD53_5AA0D974A676
#include "component.hpp"
#include "rect.hpp"
#include "paragraph.hpp"
#include "border.hpp"


namespace re {

    class Notification : public re::Component {

        private:
            re::Border border;
            re::Rect background;
            re::Paragraph text;

        public: 
            Notification(const std::string& txt);
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* C880F86C_6BD1_4324_AD53_5AA0D974A676 */
