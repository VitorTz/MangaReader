#ifndef MANGA_READER_FONT_POOL_HPP
#define MANGA_READER_FONT_POOL_HPP
#include <SFML/Graphics/Font.hpp>
#include <map>
#include "../constants.hpp"
#include "../font.hpp"


namespace re {

    class FontPool {

        private:
            static std::map<re::FontId, sf::Font*> fonts;
        
        public:
            static sf::Font* get(const re::FontId& fontId);
            static void rmv(const re::FontId& fontId);
            static void rmvAll();

    };
    
} // namespace re


#endif