#ifndef MANGA_READER_COMPONENT_HPP
#define MANGA_READER_COMPONENT_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include "../constants.hpp"
#include "../font.hpp"
#include "../globals.hpp"
#include "../util/transform.hpp"
#include "../util/state.hpp"
#include "../util/util.hpp"
#include "../util/timer.hpp"
#include "../util/image_pool.hpp"
#include "../util/font_pool.hpp"
#include "../style/style.hpp"
#include "../model/models.hpp"



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
            virtual void update(const double& dt);
            virtual void draw(sf::RenderWindow& window);
            const std::string& getName() const;

    };

    
} // namespace re


#endif