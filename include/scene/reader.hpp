#ifndef MANGA_READER_READER_HPP
#define MANGA_READER_READER_HPP
#include "scene.hpp"


namespace re {

    class Reader : public re::Scene {

        public:
            Reader(const re::ChangeScene& changeScene);            
            void update(const double& dt) override;
    };
    
} // namespace re


#endif