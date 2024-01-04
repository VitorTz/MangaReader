#include "../../include/components/manga_component.hpp"


re::MangaComponent::MangaComponent(
    re::Manga* manga
) : re::Component(manga->name + "-Component"),
    manga(manga),
    currentChapter(nullptr) {
        this->changeChapter(this->manga->lastChapterReaded);
    }



re::MangaComponent::~MangaComponent() {
    if (this->currentChapter) delete this->currentChapter;
}


void re::MangaComponent::changeChapter(const std::size_t& index) {
    if (index < this->manga->chapters.size()) {
        if (this->currentChapter) delete this->currentChapter;
        this->manga->lastChapterReaded = index;
        this->currentChapter = new re::ChapterComponent(this->manga->chapters.at(index));
        this->currentChapter->load();
    }
}


void re::MangaComponent::update(const float& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->changeChapter(this->manga->lastChapterReaded + 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->changeChapter(this->manga->lastChapterReaded - 1);
    this->currentChapter->update(dt);
}


void re::MangaComponent::draw(sf::RenderWindow& window) {
    this->currentChapter->draw(window);
}