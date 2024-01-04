#pragma once
#include <map>
#include "../components/component.hpp"

namespace re {


    class ComponentGroup {

        private:
            std::map<std::string, re::Component*> componentMap;

        public:
            ComponentGroup();
            ~ComponentGroup();
            void add(re::Component* c);
            void rmv(const std::string& name);
            re::Component* get(const std::string& name);
            void update(const float& dt);
            void draw(sf::RenderWindow& window);

    };
    
} // namespace re
