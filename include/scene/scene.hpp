#pragma once
#include <SFML/Graphics.hpp>
#include <functional>


namespace mr {

    enum SceneId {
        LibrarySceneId,
        ReaderSceneId
    };

    const SceneId main_scene = mr::SceneId::LibrarySceneId;

    typedef std::function<void(mr::SceneId)> ChangeScene;

    class Scene {

        private:
            mr::SceneId scene_id;
        
        protected:
            const mr::ChangeScene& change_scene;

        public:
            Scene(
                const mr::SceneId id, 
                const mr::ChangeScene& change_scene
            ) : scene_id(id),
                change_scene(change_scene) { }
            virtual ~Scene() = default;
            virtual void update([[maybe_unused]] double dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            const mr::SceneId& getSceneId() const {
                return scene_id;
            }

    };

}