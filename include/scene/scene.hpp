#ifndef MANGA_READER_SCENE_HPP
#define MANGA_READER_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include "../components/components.hpp"
#include "../constants.hpp"
#include "../globals.hpp"


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
            std::map<std::string, re::Component*> componentMap;
        
        protected:
            const re::ChangeScene& changeScene;
            void add(re::Component* c);
            void rmv(const std::string& s);
            re::Component* get(const std::string& s);

        public:
            Scene(const re::SceneId& sceneId, const re::ChangeScene& changeScene);
            virtual ~Scene();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            const re::SceneId& getSceneId() const;


    };
    
} // namespace re



#endif