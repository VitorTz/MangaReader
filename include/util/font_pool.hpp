#ifndef DED9FC9E_F430_4C38_8D48_4D80FBF2B88B
#define DED9FC9E_F430_4C38_8D48_4D80FBF2B88B
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <map>
#include "../constants.hpp"


namespace re {


    class FontPool {

        private:
            static std::map<re::FontId, std::unique_ptr<sf::Font>> fonts;
        
        public:
            static void load(sf::Text& t, const re::FontId& f);
            static void rmv(const re::FontId& f);
            static void rmvAll();


    };

    
} // namespace re


#endif /* DED9FC9E_F430_4C38_8D48_4D80FBF2B88B */
