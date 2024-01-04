#pragma once
#include "component.hpp"
#include "sprite.hpp"

namespace re {

    class ChapterComponent : public re::Component {
        
        private:
            re::Chapter* chapter;
            std::vector<Sprite*> images;
            void moveUp(const float& dt);
            void moveDown(const float& dt);

        public:
            ChapterComponent(re::Chapter* chapter);
            ~ChapterComponent() override;
            void load();
            void clear();
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;


    };
    
} // namespace re
