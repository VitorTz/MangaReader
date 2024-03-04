#pragma once
#include "scene.hpp"


namespace mr {

    class Reader : public mr::Scene {

        public:
            Reader(const mr::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}