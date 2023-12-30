#ifndef MANGA_READER_COMPONENT_HPP
#define MANGA_READER_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include "../constants.hpp"
#include "../util/rect.hpp"
#include "../util/util.hpp"


namespace og {


    class Component {

        private:
            const std::string name;
        
        protected:
            og::Rect rect;

        public:
            Component(const std::string& name);
            Component(const std::string& name, const og::Rect& rect);
            virtual ~Component();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            const std::string& getName() const;
            og::Rect& getRect();

    };
    
} // namespace og



#endif