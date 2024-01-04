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

    this->changeScene = [this](const re::SceneId& sceneId) {
        if (this->scene == nullptr || this->scene->getSceneId() != sceneId) {
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
    
    this->initWindow();

}


re::Window::~Window() {
    this->close();
}


void re::Window::initGlobals() {
    std::filesystem::create_directory(std::filesystem::path(re::MANGA_SETTINGS_DIR));

    for (const auto& p : std::filesystem::directory_iterator(std::filesystem::path(re::MANGA_DIR))) {
        re::Manga* manga = new re::Manga(p.path());
        re::globals::mangaByName.insert({manga->name, manga});
    }    

    std::ifstream file(re::MANGAS_SETTINGS_FILE);
    if (file.is_open()) {
        std::string line;
        std::vector<std::string> v;
        while (std::getline(file, line)) {
            re::split(line, '-', v);
            try {
                re::Manga* manga = re::globals::mangaByName.at(v[0]);
                manga->lastChapterReaded = std::stoi(v[1]);
                manga->isFavorite = (bool) std::stoi(v[2]);            
                v.clear();
            } catch (std::out_of_range& e ){
                std::cout << "Manga info not loaded " << line << ' ' << e.what() << '\n';
            }
        }
        file.close();
    }
}


void re::Window::deleteGlobals() {
    std::ofstream file(re::MANGAS_SETTINGS_FILE);
    if (file.is_open()) {
        for (const auto& pair : re::globals::mangaByName)
            file << pair.first + '-' + std::to_string(pair.second->lastChapterReaded) + '-' + std::to_string((int) pair.second->isFavorite) + '\n';
        file.close();
    }
    for (const auto& pair : re::globals::mangaByName)
        delete pair.second;
}

void re::Window::initWindow() {
    this->initGlobals();
    this->changeScene(re::mainScene);
}


void re::Window::close() {
    delete this->scene;
    this->deleteGlobals();
    re::FontPool::rmvAll();
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
    re::globals::currentTime += dt;
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