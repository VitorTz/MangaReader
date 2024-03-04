#include "../../include/window/window.hpp"


mr::Window::Window(

) : window(
    sf::VideoMode(mr::constants::SCREEN_WIDTH, mr::constants::SCREEN_HEIGHT),
    mr::constants::WINDOW_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    
    window.setFramerateLimit(mr::constants::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - mr::constants::SCREEN_WIDTH / 2,
            desktop.height / 2 - mr::constants::SCREEN_HEIGHT / 2
        )
    );

    this->change_scene = [this](const mr::SceneId id) {
        switch (id) {
            case mr::SceneId::LibrarySceneId:
                this->scene = std::make_unique<mr::Library>(this->change_scene);
                break;
            case mr::SceneId::ReaderSceneId:
                this->scene = std::make_unique<mr::Reader>(this->change_scene);
                break;
            default:
                break;
        }
    };

    change_scene(mr::main_scene);

}


void mr::Window::handle_input() {
    sf::Event e;
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}


void mr::Window::update() {
    const double dt = clock.restart().asSeconds();
    scene->update(dt);
}


void mr::Window::render() {    
    window.clear(mr::constants::SCREEN_BG_COLOR);    
    scene->draw(window);
    window.display();
}


void mr::Window::run() {
    while (window.isOpen()) {
        handle_input();
        update();
        render();
    }
}