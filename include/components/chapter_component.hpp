#ifndef MANGA_READER_CHAPTER_COMPONENT_HPP
#define MANGA_READER_CHAPTER_COMPONENT_HPP
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include "component.hpp"
#include "image_component.hpp"
#include "../model/chapter.hpp"


namespace re {


    class ChapterComponent : public re::Component {

        
        private:
            re::Chapter* chapter;
            std::vector<re::ImageComponent*> images;
        
        private:
            void moveUp(const double dt);
            void moveDown(const double dt);

        public:
            ChapterComponent(re::Chapter* chapter);
            ~ChapterComponent() override;
            void update(const double dt) override;
            void draw(sf::RenderWindow& window) override;
            void load();
            void clear();

    };
    
} // namespace re



#endif