#ifndef MANGA_READER_READER_SCENE_HPP
#define MANGA_READER_READER_SCENE_HPP
#include "scene.hpp"


namespace og {
    


    class Reader : public og::Scene {

        public:
            Reader(const og::ChangeScene& changeScene);
            void update(const double dt) override;

    };

} // namespace og



#endif