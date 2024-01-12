#include "../../include/component/chapter.hpp"


re::Chapter::Chapter(
    const std::string& path 
) : re::Component(path),
    text(
        "Chapter " + path + " has no images", 
        {}, 
        20, 
        re::FontId::Bold, 
        sf::Color::White
    ) {
    this->text.transform.setCenter(re::SCREEN_CENTER);

    for (const std::string& s : re::dirFiles(path))
        this->images.push_back(std::make_unique<re::Sprite>(s));
    
    BS::thread_pool pool(4);

    pool.detach_loop<unsigned int>(
        0,
        this->images.size(),
        [this](const unsigned int i) { this->images.at(i)->load(); },
        4
    );
    pool.wait();

    float top = 0;
    for (auto& image : this->images) {
        re::Transform& t = image->transform;
        t.setTop(top);
        t.setCenterX(re::SCREEN_CENTER.x);
        top += t.height();
    }
}


void re::Chapter::moveDown(const float& dt) {
    const float y = re::IMAGE_MOVE_SPEED * dt;
    auto& firstImage = this->images.front();
    if (firstImage->transform.top() + y <= 0) {
        for (auto& image : this->images)
            image->transform.moveY(y);
    }
}


void re::Chapter::moveUp(const float& dt) {
    const float y = -1 * re::IMAGE_MOVE_SPEED * dt;
    auto& lastImage = this->images.back();
    if (lastImage->transform.bottom() + y >= re::SCREEN_HEIGHT) {
        for (auto& image : this->images)
            image->transform.moveY(y);
    }
}


void re::Chapter::update(const float& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->moveDown(dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->moveUp(dt);
}


void re::Chapter::draw(sf::RenderWindow& window) {
    if (!this->images.empty()) {
        for (auto& image : this->images)
            if (image->transform.collide(re::SCREEN_RECT))
                image->draw(window);
    } else {
        this->text.draw(window);
    }
}