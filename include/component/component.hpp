#ifndef C55DD4D4_6472_4709_A5D6_0E489BB5E777
#define C55DD4D4_6472_4709_A5D6_0E489BB5E777
#include <SFML/Graphics.hpp>
#include <string>
#include "../util/util.hpp"
#include "../util/transform.hpp"
#include "../util/texture_pool.hpp"
#include "../constants.hpp"
#include "../globals.hpp"


namespace re {


    class Component {

        public:
            const std::string name;
            re::Transform transform;

        public:
            Component(const std::string& name);
            Component(
                const std::string& name,
                const re::Transform& transform
            );
            virtual ~Component();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace re


#endif /* C55DD4D4_6472_4709_A5D6_0E489BB5E777 */
