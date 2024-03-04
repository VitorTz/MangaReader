#pragma once
#include "scene.hpp"


namespace mr {

    class Library : public mr::Scene {

        public:
            Library(const mr::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}