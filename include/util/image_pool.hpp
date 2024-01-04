#ifndef MANGA_READER_IMAGE_POOL_HPP
#define MANGA_READER_IMAGE_POOL_HPP
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>


namespace re {


    class ImagePool {

        private:
            static std::map<std::string, sf::Texture*> images;
        
        public:
            static sf::Texture* get(const std::string& s);
            static void rmv(const std::string& s);

    };
    
} // namespace re


#endif