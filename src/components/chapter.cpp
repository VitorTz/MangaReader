#include "../../include/components/chapter.hpp"


og::Chapter::Chapter(
    const std::string& path 
) : og::Component(path),
    path(path) {
    
}


og::Chapter::~Chapter() {
    for (og::Image* image : this->images)
        delete image;
}


void og::Chapter::load() {
    std::vector<std::string>* files = og::getFiles(this->path);
    float top = 0;
    for (const std::string& s : *files) {
        og::Image* image = new og::Image(s);
        image->loadImage();
        og::Rect& rect = image->getRect();
        rect.setTop(top);
        rect.setCenterX(og::SCREEN_CENTER.x);
        top += rect.height();
        this->images.push_back(image);
    }
    delete files;
}


void og::Chapter::clear() {
    for (og::Image* image : this->images)
        delete image;
    this->images.clear();
}


void og::Chapter::moveDown(const double  dt) {
    const float delta = dt * og::SPEED;
    og::Image* firstImage = this->images.front();
    if (firstImage->getRect().top() + delta > 0)
        return;

    for (og::Image* image : this->images) {
        og::Rect& rect = image->getRect();
        rect.moveY(delta);
    }
}


void og::Chapter::moveUp(const double  dt) {
    const float delta = dt * og::SPEED * -1;
    og::Image* lastImage = this->images.back();
    if (lastImage->getRect().bottom() + delta < og::SCREEN_HEIGHT)
        return;
        
    for (og::Image* image : this->images) {
        og::Rect& rect = image->getRect();
        rect.moveY(delta);
    }
}


void og::Chapter::update(const double dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        this->moveDown(dt);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->moveUp(dt);
}


void og::Chapter::draw(sf::RenderWindow& window) {
    for (og::Image* image : this->images) {
        const og::Rect& rect = image->getRect();
        if (rect.collideRect(og::SCREEN_RECT))
            image->draw(window);
    }        
}