#pragma once
#include "scene.hpp"


namespace re {

    class Library : public re::Scene {

        public:
            Library(const re::ChangeScene& changeScene);
            void update(const float& dt) override;

    };
    
} // namespace re
