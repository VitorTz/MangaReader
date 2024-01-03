#include "../../include/window/window.hpp"
#include <iostream>


re::Window::Window(

) : window(
    sf::VideoMode(re::SCREEN_WIDTH, re::SCREEN_HEIGHT),
    re::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(re::FPS);
    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        {
            (int) (desktop.width / 2 - re::SCREEN_WIDTH / 2),
            (int) (desktop.height / 2 - re::SCREEN_HEIGHT / 2)
        }
    );

    re::globals::initGlobals();

    this->changeScene = [this](const re::SceneId& sceneId) {
        if (this->scene == nullptr || this->scene->getSceneId() != sceneId) {
            if (this->scene) delete this->scene;
            switch (sceneId) {
                case re::SceneId::LibraryId:
                    this->scene = new re::Library(this->changeScene);
                    break;
                default:
                    break;
            }
        }
    };
    
    this->changeScene(re::mainScene);

}


re::Window::~Window() {
    delete this->scene;
    re::globals::deleteGlobals();
}


void re::Window::handleInput() {
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            default:
                break;
        }
    }
}


void re::Window::update() {
    const double dt = this->clock.restart().asSeconds();
    this->scene->update(dt);
}


void re::Window::draw() {
    this->window.clear(re::SCREEN_BG_COLOR);
    this->scene->draw(this->window);
    this->window.display();
}


void re::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}