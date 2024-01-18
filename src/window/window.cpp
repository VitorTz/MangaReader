#include "../../include/window/window.hpp"



re::Window::Window(

) : window(
    sf::VideoMode(re::SCREEN_WIDTH, re::SCREEN_HEIGHT),
    re::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(re::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - re::SCREEN_WIDTH / 2,
            desktop.height / 2 - re::SCREEN_HEIGHT / 2 - 20
        )
    );
    
    this->changeScene = [this](const re::SceneId& id) {
        if (this->scene == nullptr || this->scene->id != id) {
            switch (id) {
                case re::SceneId::ReaderId:
                    this->scene = std::make_unique<re::Reader>(this->changeScene);                    
                    break;
                case re::SceneId::LibraryId:
                    this->scene = std::make_unique<re::Library>(this->changeScene);                    
                    break;
                default:
                    break;
            }            
        }
    };

    this->changeScene(re::mainScene);

}


void re::Window::handleInput() {
    re::globals::pressedKeys.clear();
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                re::globals::pressedKeys.insert(e.key.code);
                break;
            default:
                break;
        }
    }
}


void re::Window::update() {
    const float dt = this->clock.restart().asSeconds();
    if (this->window.hasFocus()) {
        re::globals::currentTime += dt;
        re::NotificationManager::update(dt);
        this->scene->update(dt);
    }
}


void re::Window::draw() {
    this->window.clear(re::SCREEN_BG_COLOR);
    this->scene->draw(this->window);
    re::NotificationManager::draw(this->window);
    this->window.display();
}


void re::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}