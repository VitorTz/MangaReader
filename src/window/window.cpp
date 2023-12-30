#include "../../include/window/window.hpp"


og::Window::Window(

) : window(
    sf::VideoMode(og::SCREEN_WIDTH, og::SCREEN_HEIGHT),
    og::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
), scene(nullptr) {
    this->window.setFramerateLimit(og::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();    
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::SCREEN_WIDTH / 2,
            desktop.height / 2 - og::SCREEN_HEIGHT / 2
        )
    );
    
    this->changeScene = [this](const og::SceneId& sceneId) {
        if (this->scene == nullptr || this->scene->getSceneId() != sceneId) {
            if (this->scene != nullptr) delete this->scene;
            switch (sceneId) {
                case og::SceneId::MyLibraryId:
                    this->scene = new og::MyLibrary(this->changeScene);
                    break;
                case og::SceneId::ReaderId:
                    this->scene = new og::Reader(this->changeScene);
                    break;
                default:
                    break;
            }
        }
    };
    
    this->changeScene(og::mainScene);

}


og::Window::~Window() {
    delete this->scene;
    og::ImagePool::rmvAll();
}


void og::Window::update() {
    const double dt = this->clock.restart().asSeconds();
    this->scene->update(dt);
}


void og::Window::handleInput() {
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


void og::Window::draw() {
    this->window.clear(og::SCREEN_COLOR);
    this->scene->draw(this->window);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}