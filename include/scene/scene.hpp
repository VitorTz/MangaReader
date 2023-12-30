#ifndef MANGA_READER_SCENE_HPP
#define MANGA_READER_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>


namespace og {

    enum SceneId {
        Library,
        Reader
    };

    const og::SceneId mainScene = og::SceneId::Library;

    typedef std::function<void(const og::SceneId&)> ChangeScene;

    class Scene {

        private:
            const og::SceneId sceneId;
            const og::ChangeScene& changeScene;

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