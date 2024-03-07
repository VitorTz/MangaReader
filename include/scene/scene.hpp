#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "../constants.hpp"


namespace mr {

    enum SceneId {
        LibrarySceneId,
        ReaderSceneId
    };

    typedef std::map<std::string, std::string> SceneInfo;
    typedef std::function<void(mr::SceneId, const mr::SceneInfo& scene_info)> ChangeScene;

    class Scene {

        private:
            mr::SceneId id;
        
        protected:
            const mr::ChangeScene& change_scene;
        
        public:
            Scene(
                mr::SceneId id, 
                const mr::ChangeScene& change_scene,
                [[maybe_unused]] const mr::SceneInfo& sceneInfo = { }
            ) : id(id), change_scene(change_scene) { }
            virtual ~Scene() = default;
            virtual void update(double dt) = 0;
            virtual void draw(sf::RenderWindow& window) = 0;
            const mr::SceneId& getSceneId() const { return id; }

    };

}