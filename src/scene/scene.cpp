#include "../../include/scene.hpp"
#include <iostream>



mr::Scene::Scene(
    const mr::SceneId id,
    const mr::ChangeScene& changeScene 
) : id(id),
    change_scene(changeScene) {

    }


mr::Scene::~Scene() = default;


mr::SceneId mr::Scene::getId() const {
    return id;
}

