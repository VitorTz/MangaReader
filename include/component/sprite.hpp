#ifndef C15CA644_6F8F_4D45_B51F_93DC94A99766
#define C15CA644_6F8F_4D45_B51F_93DC94A99766
#include "../util/texture_pool.hpp"
#include "component.hpp"
#include <filesystem>

namespace re {

    class Sprite : public re::Component {

        private:
            sf::Sprite sprite;

        public:
            Sprite(const std::filesystem::path& path);
            Sprite(
                const std::filesystem::path& path,
                const re::Transform& transform
            );
            ~Sprite() override;
            void load();
            void load(const float maxWidth);
            void setMaxWidth(const float width);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re



#endif /* C15CA644_6F8F_4D45_B51F_93DC94A99766 */
