#ifndef MANGA_READER_MY_LIBRARY_SCENE_HPP
#define MANGA_READER_MY_LIBRARY_SCENE_HPP
#include "scene.hpp"


namespace og {


    class MyLibrary : public og::Scene {

        public:
            MyLibrary(const og::ChangeScene& changeScene);
            ~MyLibrary();
            void update(const double dt) override;

    };
    
} // namespace og



#endif