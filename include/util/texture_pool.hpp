#ifndef FF58A3E1_400B_4ED2_9C7A_B63555181C3B
#define FF58A3E1_400B_4ED2_9C7A_B63555181C3B
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <map>
#include <mutex>


namespace re {


    class TexturePool {

        private:
            static std::map<std::string, std::unique_ptr<sf::Texture>> textureMap;
            static std::mutex m;
            
        public:
            static void load(const std::string& path);
            static void load(const std::string& path, sf::Sprite& sprite);
            static void rmv(const std::string& path);
            static void rmvAll();

    };
    
} // namespace re


#endif /* FF58A3E1_400B_4ED2_9C7A_B63555181C3B */
