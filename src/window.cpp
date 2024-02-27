#include "../include/window.hpp"


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

    changeScene = [this](const mr::SceneId id) {
        switch (id) {
            case mr::SceneId::LibrarySceneId:
                this->scene = std::make_unique<mr::LibraryScene>(this->changeScene);
                break;
            case mr::SceneId::ReaderSceneId:
                this->scene = std::make_unique<mr::ReaderScene>(this->changeScene);
                break;
            default:
                break;
        }
    };
    
    mr::load_mangas(&mr::globals::mangas);
    changeScene(mr::main_scene);   

}


mr::Window::~Window() {
    mr::dump_mangas(&mr::globals::mangas);
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
    mr::globals::mouse_pos = sf::Mouse::getPosition(window);
    mr::globals::mouse_is_clicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
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