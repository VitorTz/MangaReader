#ifndef MANGA_READER_COMPONENT_GROUP_HPP
#define MANGA_READER_COMPONENT_GROUP_HPP
#include "../components/component.hpp"
#include <map>


namespace re {

    class ComponentGroup {

        private:
            std::map<std::string, re::Component*> componentMap;

        public:
            ComponentGroup();
            ~ComponentGroup();
            void add(re::Component* c);
            void rmv(const std::string& s);
            re::Component* get(const std::string& s);
            void update(const double& dt);
            void draw(sf::RenderWindow& window);

    };
    
} // namespace re


#endif