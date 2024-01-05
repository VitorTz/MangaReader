#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <map>
#include "../style/style.hpp"
#include "../util/image_pool.hpp"
#include "../util/font_pool.hpp"
#include "../util/transform.hpp"
#include "../constants.hpp"
#include "../globals.hpp"
#include "../model/models.hpp"
#include "../util/util.hpp"
#include "../util/timer.hpp"


namespace re {


    class Component {

        public:
            const std::string name;
            re::Transform transform;
        
        public:
            Component(const std::string& name, const re::Transform& t);
            Component(const std::string& name);
            virtual ~Component();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace re
