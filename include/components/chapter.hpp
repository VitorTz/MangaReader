#ifndef MANGA_READER_CHAPTER_HPP
#define MANGA_READER_CHAPTER_HPP
#include <vector>
#include "component.hpp"
#include "image.hpp"


namespace og {

    class Chapter : public og::Component {

        private:
            const std::string path;
            std::vector<og::Image*> images;
            void moveUp(const double dt);
            void moveDown(const double dt);

        public:
            Chapter(const std::string& path);
            ~Chapter() override;
            void update(const double dt) override;
            void draw(sf::RenderWindow& window) override;
            void load();
            void clear();

    };
    
} // namespace og


#endif