#ifndef MANGA_READER_SCENE_HPP
#define MANGA_READER_SCENE_HPP
#include <functional>
#include "../components/components.hpp"
#include "../util/component_group.hpp"


namespace re {

    enum class SceneId {
        LibraryId,
        ReaderId
    };

    const re::SceneId mainScene = re::SceneId::LibraryId;

    typedef std::function<void(const re::SceneId&)> ChangeScene;

    class Scene {

        private:
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
            virtual void update(const double& dt);
            virtual void draw(sf::RenderWindow& window);
            const re::SceneId& getSceneId() const;


    };
    
} // namespace re



#endif