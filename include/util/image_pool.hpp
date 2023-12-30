#ifndef MANGA_READER_IMAGE_POOL_HPP
#define MANGA_READER_IMAGE_POOL_HPP
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>


namespace og {

    typedef struct ImageSource {
        sf::Sprite* sprite;
        sf::Texture* texture;
    } ImageSource;


    class ImagePool {

        private:
            static std::map<std::string, og::ImageSource*> images;
        
        public:
            static const og::ImageSource* getImage(const std::string& path);
            static void rmvImage(const std::string& path);
            static void rmvAll();

    };
    
} // namespace og



#endif