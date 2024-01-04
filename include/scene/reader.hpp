#pragma once
#include "scene.hpp"


namespace re {

    class Reader : public re::Scene {


        public:
            Reader(const re::ChangeScene& changeScene);
            void update(const float& dt) override;

    };
    
} // namespace re
