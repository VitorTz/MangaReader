#ifndef MANGA_READER_IMAGE_COMPONENT_HPP
#define MANGA_READER_IMAGE_COMPONENT_HPP
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "component.hpp"
#include <map>
#include "../util/image_pool.hpp"
#include "../model/image.hpp"


namespace re {

    class ImageComponent : public re::Component {

        private:
            re::Image* image;
            sf::Sprite sprite;
        
        public:
            ImageComponent(re::Image* image);
            ~ImageComponent() override;
            void load();
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re



#endif