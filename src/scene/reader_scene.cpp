#include "../../include/scene/reader_scene.hpp"


mr::ReaderScene::ReaderScene(
    const mr::ChangeScene& change_scene,
    const mr::SceneInfo& scene_info 
) : mr::Scene(mr::SceneId::ReaderSceneId, change_scene, scene_info),
    manga(scene_info.at("manga_path")) {
    std::cout << "[OPEN READER SCENE]\n";
    load_chapter();
}



void mr::ReaderScene::load_chapter() {
    if (manga.chapters.empty()) {
        warning.setTxt("Manga " + manga.name + "has no chapters");
        warning.center_on_screen();
        return;
    }

    images.clear();
    
    warning.setTxt(manga.name + '/' + "Chapter " + std::to_string(manga.last_readed_chapter) + " has no images");
    warning.center_on_screen();

    for (const auto& p : std::filesystem::directory_iterator(manga.chapters[manga.last_readed_chapter])) {
        const std::filesystem::path path = p.path();
        if (std::filesystem::is_regular_file(path)) {
            images.push_back(mr::Image(path));
        }
    }

    std::sort(
        images.begin(), images.end(),
        [](const mr::Image& l, const mr::Image& r) {
            return std::stoi(l.getName()) < std::stoi(r.getName());
        }
    );

    BS::thread_pool pool(6);

    pool.detach_loop<unsigned int>(
        0, images.size(), 
        [this](const unsigned int i) {
            this->images[i].load();
        }
    );
    pool.wait();

    float top = 0;
    for (mr::Image& image : images) {
        image.fit_on_screen();
        image.center_on_screen();
        image.pos.y = top;
        top += image.size.y;
    }

}


void mr::ReaderScene::change_chapter(const std::size_t index) {
    if (index < manga.chapters.size()) {
        manga.last_readed_chapter = index;
        load_chapter();
    }
}


void mr::ReaderScene::update(const double dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        change_scene(mr::SceneId::LibrarySceneId, { });
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        change_chapter(manga.last_readed_chapter + 1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        change_chapter(manga.last_readed_chapter - 1);
    }

    if (images.empty()) {
        return;
    }

    double distance = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        distance = dt * mr::constants::SCROLL_SPEED * -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        distance = dt * mr::constants::SCROLL_SPEED;
    }

    const mr::Image& last = images.back();

    if (
        images.front().pos.y + distance <= 0 && 
        last.pos.y + last.size.y + distance >= mr::constants::SCREEN_HEIGHT
    ) {
        for (mr::Image& image : images) {
            image.pos.y += distance;
        }
    }

}


void mr::ReaderScene::draw(sf::RenderWindow& window) {
    if (manga.chapters.empty() || images.empty()) {
        warning.draw(window);
        return;
    }
    for (mr::Image& image : images) {
        if (
            image.pos.y <= 0 || 
            image.pos.y + image.size.y >= mr::constants::SCREEN_HEIGHT
        ) {
            image.draw(window);
        }
    }    
}