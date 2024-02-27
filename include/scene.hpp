#pragma once
#include "SFML/Graphics.hpp"
#include "globals.hpp"
#include "grid/grid_item.hpp"
#include <memory>
#include "util/timer.hpp"
#include <functional>
#include "../libs/thread-pool-master/include/BS_thread_pool.hpp"


namespace mr {


    enum SceneId {
        ReaderSceneId,
        LibrarySceneId
    };

    const mr::SceneId main_scene = mr::SceneId::LibrarySceneId;


    typedef std::function<void(mr::SceneId)> ChangeScene;

    class Scene {

        private:
            mr::SceneId id;

        protected:
            const mr::ChangeScene& change_scene;

        public:
            Scene(mr::SceneId id, const mr::ChangeScene& changeScene);
            virtual ~Scene();
            virtual void update([[maybe_unused]] double dt) { }
            virtual void draw([[maybe_unused]] sf::RenderWindow& window) { }
            mr::SceneId getId() const;

    };


    class LibraryScene : public mr::Scene {

        private:
            std::vector<std::unique_ptr<mr::GridItem>> grid;
            const std::vector<sf::Keyboard::Key> keys = {
                sf::Keyboard::Up,
                sf::Keyboard::Right,
                sf::Keyboard::Down,
                sf::Keyboard::Left,
                sf::Keyboard::Enter
            };
            mr::Timer keyboard_timer = mr::Timer(20);
            std::size_t current_item = 0;
        
        private:
            void grid_move_up();
            void grid_move_down();
            void grid_select_item();
            void change_current_selected_item(std::size_t index);
            void handle_keyboard();            

        public:
            LibraryScene(const mr::ChangeScene& changeScene);
            void update(const double dt) override;
            void draw(sf::RenderWindow& window) override;

    };


    class ReaderScene : public mr::Scene {

        private:
            mr::Manga* manga;
            std::vector<mr::image*> images;

        private:
            void destroy_images();
            void change_chapter(std::size_t index);
            void handle_image_movement(double dt);
            void handle_chapter_change();

        public:
            ReaderScene(const mr::ChangeScene& changeScene);
            ~ReaderScene() override;
            void update(const double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

    
} // namespace mr
