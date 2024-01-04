#ifndef MANGA_READER_IMAGE_COMPONENT_HPP
#define MANGA_READER_IMAGE_COMPONENT_HPP
#include "component.hpp"
#include "../model/image.hpp"


namespace re {

    class ImageComponent : public re::Component {

        private:
            re::Image* image;
            sf::Sprite sprite;
        
        public:
            ImageComponent(re::Image* image);            
            void load();
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re



#endif