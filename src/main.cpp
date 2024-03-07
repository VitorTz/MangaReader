#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include "../include/scene/scenes.hpp"
#include "../include/constants.hpp"
#include "../include/util/image.hpp"


int main(void) {

    sf::RenderWindow window(
        sf::VideoMode(mr::constants::SCREEN_WIDTH, mr::constants::SCREEN_HEIGHT),
        mr::constants::WINDOW_TITLE,
        sf::Style::Close | sf::Style::Titlebar
    );

    window.setFramerateLimit(mr::constants::FPS);
    sf::Clock clock;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - mr::constants::SCREEN_WIDTH / 2,
            desktop.height / 2 - mr::constants::SCREEN_HEIGHT / 2
        )
    );

    std::unique_ptr<mr::Scene> scene;
    mr::ChangeScene change_scene = [&change_scene, &scene](const mr::SceneId id, const mr::SceneInfo& info) {
        switch (id) {
            case mr::SceneId::LibrarySceneId:
                scene = std::make_unique<mr::LibraryScene>(change_scene, info);
                break;
            case mr::SceneId::ReaderSceneId:
                scene = std::make_unique<mr::ReaderScene>(change_scene, info);
                break;
            default:
                break;
        }
    };

    change_scene(mr::SceneId::LibrarySceneId, { });        

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        const double dt = clock.restart().asSeconds();
        scene->update(dt);

        window.clear(mr::constants::WINDOW_BG_COLOR);
        scene->draw(window);                
        window.display();

    }

    return 0;
}