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



void re::ChapterComponent::moveDown(const float& dt) {
    const float deltaY = re::constants::IMAGE_MOVE_SPEED * dt;
    re::Sprite* firstImage = this->images.front();
    if (firstImage->transform.top() + deltaY > 0)
        return;
    for (re::Sprite* sprite : this->images)
        sprite->transform.moveY(deltaY);
}


void re::ChapterComponent::moveUp(const float& dt) {
    const float deltaY = -1 * re::constants::IMAGE_MOVE_SPEED * dt;
    re::Sprite* lastImage = this->images.back();
    if (lastImage->transform.bottom() + deltaY < re::constants::SCR_HEIGHT)
        return;
    for (re::Sprite* sprite : this->images)
        sprite->transform.moveY(deltaY);
}


void re::ChapterComponent::update(const float& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->moveDown(dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->moveUp(dt);
        
}

void re::ChapterComponent::draw(sf::RenderWindow& window) {
    for (re::Sprite* sprite : this->images)
        if (sprite->transform.collide(re::constants::SCR_TRANSFORM))
            sprite->draw(window);
}