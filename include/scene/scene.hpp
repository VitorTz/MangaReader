#ifndef DD23C6ED_905A_430B_A3A0_F71BB6727A9B
#define DD23C6ED_905A_430B_A3A0_F71BB6727A9B
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>
#include <map>
#include "../component/components.hpp"
#include "../globals.hpp"
#include "../constants.hpp"


namespace re {

    enum SceneId {
        LibraryId,
        ReaderId
    };

    typedef std::function<void(const re::SceneId&)> ChangeScene;

    const re::SceneId mainScene = re::SceneId::ReaderId;

    class Scene {

        public:
            const re::SceneId id;

        protected:
            std::map<std::string, std::unique_ptr<re::Component>> componentMap;
            const re::ChangeScene& changeScene;

        public:
            Scene(
                const re::SceneId& id,
                const re::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace re


#endif /* DD23C6ED_905A_430B_A3A0_F71BB6727A9B */
