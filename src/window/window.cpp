#include "../../include/window/window.hpp"


re::Window::Window(

) : window(
    sf::VideoMode(re::constants::SCR_WIDTH, re::constants::SCR_HEIGHT),
    re::constants::SCR_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {

    this->window.setFramerateLimit(re::constants::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - re::constants::SCR_WIDTH / 2,
            desktop.height / 2 - re::constants::SCR_HEIGHT / 2
        )
    );

    this->changeScene = [this](const re::SceneId& sceneId) {
        if (this->scene == nullptr || this->scene->sceneId != sceneId) {
            if (this->scene) delete this->scene;
            switch (sceneId) {
                case re::SceneId::LibraryId:
                    this->scene = new re::Library(this->changeScene);
                    break;
                case re::SceneId::ReaderId:
                    this->scene = new re::Reader(this->changeScene);
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
    const float dt = this->clock.restart().asSeconds();
    re::globals::mousePos = (sf::Vector2f) sf::Mouse::getPosition(this->window);
    this->scene->update(dt);
}


void re::Window::draw() {
    this->window.clear(re::constants::SCR_COLOR);
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