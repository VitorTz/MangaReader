#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <memory>
#include <mutex>
#include <map>
#include "style.hpp"
#include "../constants.hpp"


namespace mr {


    class Image {

        private:
            static std::mutex m; 
            static std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> texture_map;

        private:
            std::filesystem::path path;
            std::string name;
            sf::Sprite sprite;            
        
        public:
            sf::Vector2f pos;
            sf::Vector2f size;

        public:            
            explicit Image(const std::filesystem::path& path);            
            ~Image();
            void center_on_screen();
            void fit_on_screen();
            void load();
            void draw(sf::RenderWindow& window);
            const std::string& getName() const;

    };

    void draw_border(mr::Image* image, const mr::style::border_t& border, sf::RenderWindow& window);
    
    void draw_border(
        sf::Vector2f pos, 
        sf::Vector2f size, 
        const mr::style::border_t& border,
        sf::RenderWindow& window
    );

}