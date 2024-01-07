#include "../../include/components/chapter_component.hpp"
#include <iostream>


re::ChapterComponent::ChapterComponent(
    re::Chapter* chapter
) : re::Component(chapter->name + "-Component"),
    chapter(chapter) {

    }


re::ChapterComponent::~ChapterComponent() {
    this->clear();
}


void re::ChapterComponent::clear() {
    this->chapter->clearImages();
    re::deletePtrVector(this->images);
}


void re::ChapterComponent::load() {
    this->clear();
    this->chapter->loadImages();
    float top = 0;
    for (re::Image* image : this->chapter->images) {
        re::Sprite* sprite = new re::Sprite(image->path);
        re::Transform& t = sprite->transform;
        t.setTop(top);
        t.setCenterX(re::constants::SCR_CENTER.x);
        top += t.height();
        this->images.push_back(sprite);
    }
}


void re::ChapterComponent::move(const float& dt) {
    const float y = re::constants::IMAGE_MOVE_SPEED * dt;
    re::Sprite* firstImage = this->images.front();
    re::Sprite* lastImage = this->images.back();
    if (
        firstImage->transform.top() + y <= 0 &&
        lastImage->transform.bottom() + y >= re::constants::SCR_SIZE.y
    ) {
        for (re::Sprite* sprite : this->images)
            sprite->transform.moveY(y);
    }
}



void re::ChapterComponent::update(const float& dt) {     
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->move(dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->move(-dt);
        
}

void re::ChapterComponent::draw(sf::RenderWindow& window) {
    for (re::Sprite* sprite : this->images)
        if (sprite->transform.collide(re::constants::SCR_TRANSFORM))
            sprite->draw(window);
}