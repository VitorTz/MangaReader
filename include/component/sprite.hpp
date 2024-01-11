#ifndef C15CA644_6F8F_4D45_B51F_93DC94A99766
#define C15CA644_6F8F_4D45_B51F_93DC94A99766
#include "component.hpp"


namespace re {

    class Sprite : public re::Component {

        private:
            sf::Sprite sprite;

        public:
            Sprite(const std::string& path);
            Sprite(
                const std::string& path,
                const re::Transform& transform
            );
            ~Sprite() override;
            void load();
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re



#endif /* C15CA644_6F8F_4D45_B51F_93DC94A99766 */
