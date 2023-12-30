#ifndef MANGA_READER_SCENE_HPP
#define MANGA_READER_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include "../constants.hpp"
#include "../components/components.hpp"


namespace og {

    enum SceneId {
        MyLibraryId,
        ReaderId
    };

    const og::SceneId mainScene = og::SceneId::MyLibraryId;

    typedef std::function<void(const og::SceneId&)> ChangeScene;

    class Scene {

        private:
            const og::SceneId sceneId;
            std::map<std::string, og::Component*> componentMap;
        
        protected:
            const og::ChangeScene& changeScene;
            void addComponent(og::Component* c);
            void rmvComponent(const std::string& name);
            og::Component* getComponent(const std::string& name) const;

        public:
            Scene(
                const og::SceneId& sceneId, 
                const og::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            const og::SceneId& getSceneId() const;

    };
    
} // namespace og


#endif