#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>



namespace re {


    namespace Font {
        
        enum class FontId {

            Regular,
            Light,
            SemiBold,
            Bold

        };

        const std::map<re::Font::FontId, std::string> fontPathById = {
            {re::Font::FontId::Light, "res/font/Roboto-Thin.ttf"},
            {re::Font::FontId::Regular, "res/font/Roboto-Regular.ttf"},
            {re::Font::FontId::SemiBold, "res/font/Roboto-Medium.ttf"},
            {re::Font::FontId::Bold, "res/font/Roboto-Bold.ttf"}
        };


        class FontPool {

            private:
                static std::map<re::Font::FontId, sf::Font*> fonts;
            
            public:
                static sf::Font* get(const re::Font::FontId& fontId);
                static void rmv(const re::Font::FontId& fontId);
                static void rmvAll();

        };


        sf::Vector2f getStrSize(
            const std::string& s,
            const std::size_t& characterSize,
            const re::Font::FontId& fontId
        );

    } // namespace Font
    

    
} // namespace re
