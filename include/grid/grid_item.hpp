#pragma once
#include "../constants.hpp"
#include "../globals.hpp"
#include "../util/image.hpp"
#include "../manga.hpp"


namespace mr {

    class GridItem {

        private:            
            mr::Manga* manga;
            std::string manga_name;
            sf::Text txt;
            sf::Font font;
            mr::image* image;
            sf::RectangleShape txt_background;
            sf::RectangleShape border;
            sf::Vector2f pos;
            sf::Vector2f size;            
            bool on_hover = false;
        
        private:
            void draw_border(sf::RenderWindow& window);

        public:
            GridItem(
                const std::string& manga_name,
                const std::filesystem::path& cover_image,
                const sf::Vector2f pos
            );
            ~GridItem();            
            void set_on_hover(bool on_hover);
            void draw(sf::RenderWindow& window);
            const sf::Vector2f& getSize() const;
            const sf::Vector2f& getPos() const;
            void setPos(const sf::Vector2f pos);
            const std::string& get_manga_name() const;

    };
    
} // namespace mr
