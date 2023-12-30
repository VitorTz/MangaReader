#ifndef MANGA_READER_IMAGE_HPP
#define MANGA_READER_IMAGE_HPP
#include "component.hpp"
#include "../util/image_pool.hpp"


namespace og {


    class Image : public og::Component {
    
        private:
            const std::string path;

        public:
            Image(const std::string& path);
            ~Image() override;
            void loadImage();
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace og


#endif