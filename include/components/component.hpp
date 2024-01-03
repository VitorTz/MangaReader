#ifndef MANGA_READER_COMPONENT_HPP
#define MANGA_READER_COMPONENT_HPP
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "../constants.hpp"
#include "../util/transform.hpp"
#include "../globals.hpp"
#include "../util/util.hpp"



namespace re {

    class Component {

        protected:
            const std::string name;
        
        public:
            re::Transform transform;
        
        public:
            Component(const std::string& name);
            Component(const std::string& name, const re::Transform& transform);
            virtual ~Component();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            const std::string& getName() const;


    };
    
} // namespace re


#endif