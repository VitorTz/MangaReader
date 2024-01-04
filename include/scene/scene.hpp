#pragma once
#include "../components/components.hpp"
#include "../util/component_group.hpp"
#include <functional>


namespace re {

    enum class SceneId {
        LibraryId,
        ReaderId
    };

    const re::SceneId mainScene = re::SceneId::LibraryId;

    typedef std::function<void(const re::SceneId&)> ChangeScene;

    class Scene {

        public:
            const re::SceneId sceneId;
        
        protected:
            const re::ChangeScene& changeScene;
            re::ComponentGroup componentGroup;

        public:

            Scene(
                const re::SceneId& sceneId,
                const re::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const float& dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace re
