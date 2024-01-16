#ifndef B076B339_290B_4F44_B01C_1EEB6534AE49
#define B076B339_290B_4F44_B01C_1EEB6534AE49
#include "sprite.hpp"
#include "text.hpp"
#include "../thread-pool/include/BS_thread_pool.hpp"


namespace re {

    class Chapter : public re::Component {

        private:
            re::Text text;
            std::vector<std::unique_ptr<re::Sprite>> images;
        
        private:
            void moveUp(const float& dt);
            void moveDown(const float& dt);

        public:
            explicit Chapter(const std::filesystem::path& path);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif /* B076B339_290B_4F44_B01C_1EEB6534AE49 */
