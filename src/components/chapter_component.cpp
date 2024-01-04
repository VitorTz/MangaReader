#include "../../include/components/chapter_component.hpp"


re::ChapterComponent::ChapterComponent(
    re::Chapter* chapter
) : re::Component(chapter->name),
    chapter(chapter) {

    }


re::ChapterComponent::~ChapterComponent() {
    re::clearPtrVector(this->images);
}


void re::ChapterComponent::moveDown(const double dt) {
    const float deltaY = re::IMAGE_MOVE_SPEED * dt;
    re::ImageComponent* firstImage = this->images.front();
    if (firstImage->transform.top() + deltaY <= 0)
        for (re::ImageComponent* image : this->images)
            image->transform.moveY(deltaY);
} 


void re::ChapterComponent::moveUp(const double dt) {
    const float deltaY = re::IMAGE_MOVE_SPEED * dt * -1;
    re::ImageComponent* lastImage = this->images.back();
    if (lastImage->transform.bottom() + deltaY >= re::SCREEN_HEIGHT)
        for (re::ImageComponent* image : this->images)
            image->transform.moveY(deltaY); 
} 


void re::ChapterComponent::update(const double& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->moveDown(dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->moveUp(dt);
}


void re::ChapterComponent::draw(sf::RenderWindow& window) {
    for (re::ImageComponent* image : this->images)
        if (image->transform.collide(re::SCREEN_RECT))
            image->draw(window);
}


void re::ChapterComponent::clear() {
    this->chapter->clearImages();
    re::clearPtrVector(this->images);
}

void re::ChapterComponent::load() {
    this->clear();
    this->chapter->loadImages();
    float top = 0;
    for (re::Image* imageModel : this->chapter->images) {
        re::ImageComponent* imageComponent = new re::ImageComponent(imageModel);
        imageComponent->load();
        re::Transform& t = imageComponent->transform;
        t.setTop(top);
        t.setCenterX(re::SCREEN_CENTER.x);
        top += t.height();
        this->images.push_back(imageComponent);
    }
}