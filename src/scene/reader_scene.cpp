#include "../../include/scene.hpp"


mr::ReaderScene::ReaderScene(
    const mr::ChangeScene& changeScene
) : mr::Scene(mr::SceneId::ReaderSceneId, changeScene) {
    manga = mr::globals::mangas.at(mr::globals::manga_reading).get();    
    change_chapter(manga->get_current_chapter_num());
}


void mr::ReaderScene::destroy_images() {
    if (images.empty()) {
        return;
    }
    for (mr::image* image : images) {
        mr::image_destroy(image);
    }
    images.clear();
}


mr::ReaderScene::~ReaderScene() {
    destroy_images();
}


void mr::ReaderScene::change_chapter(const std::size_t index) {
    if (manga->change_chapter_num(index)) {
        destroy_images();
        std::vector<std::filesystem::path> files = mr::get_images_files_from_dir(manga->get_current_chapter_path());
        for (const auto& image_file : files) {
            images.push_back(mr::image_create(image_file));
        }

        BS::thread_pool pool(4);

        pool.detach_loop<unsigned int>(
            0,
            images.size(),
            [this](const unsigned int i) {
                mr::image_load(this->images[i]);
            }
        );

        pool.wait();

        float top = 0;
        for (mr::image* image : images) {
            // fit image on screen
            if (image->size.x > mr::constants::SCREEN_WIDTH) {
                const float d = mr::constants::SCREEN_WIDTH / image->size.x;
                image->size.x *= d;
                image->size.y *= d;
                image->sprite.setScale({d, d});
            }            
            image->pos.x = mr::constants::SCREEN_SIZE.x / 2 - image->size.x / 2.f;
            image->pos.y = top;
            top += image->size.y;
        }
        
    }
}


void mr::ReaderScene::handle_image_movement(const double dt) {
    if (images.empty()) {
        return;
    }

    double distance = dt * mr::constants::SCROLL_SPEED;
    double direction = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = 1;
    }

    if (direction != 0) {
        distance *= direction;
        mr::image* first_image = images.front();
        mr::image* last_image = images.back();
        if (
            first_image->pos.y + distance <= 0 &&
            last_image->pos.y + last_image->size.y + distance >= mr::constants::SCREEN_HEIGHT
        ) {
            for (mr::image* image : images) {
                image->pos.y += distance;
            }
        }
    }   
}


void mr::ReaderScene::handle_chapter_change() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        change_chapter(manga->get_current_chapter_num() + 1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        change_chapter(manga->get_current_chapter_num() - 1);
    }
}


void mr::ReaderScene::update(const double dt) {
    handle_image_movement(dt);
    handle_chapter_change();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {        
        mr::globals::manga_reading = "";
        change_scene(mr::LibrarySceneId);
    }
}


void mr::ReaderScene::draw(sf::RenderWindow& window) {
    for (mr::image* image : images) {
        mr::image_draw(image, window);
    }
}