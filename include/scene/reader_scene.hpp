#pragma once
#include "scene.hpp"
#include "../util/manga.hpp"
#include "../util/image.hpp"
#include "../util/text.hpp"
#include "../../libs//thread-pool-master/include/BS_thread_pool.hpp"


namespace mr {


    class ReaderScene : public Scene {

        private:
            mr::Manga manga;
            mr::Text warning = mr::Text("CHAPTER HAS 0 IMAGES", mr::style::TXT_HEADER);
            std::vector<mr::Image> images;
        
        private:
            void load_chapter();
            void change_chapter(std::size_t index);

        public:
            ReaderScene(
                const mr::ChangeScene& changeScene,
                const mr::SceneInfo& scene_info
            );
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;
        
    };

}