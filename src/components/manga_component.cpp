#include "../../include/components/manga_component.hpp"


re::MangaComponent::MangaComponent(
    re::Manga* manga
) : re::Component(manga->name),
    manga(manga),
    currentChapter(nullptr),
    currentChapterIndex(0) {

    }


re::MangaComponent::~MangaComponent() {
    for (re::ChapterComponent* chapterComponent : this->chapters)
        delete chapterComponent;
}


void re::MangaComponent::nextChapter() {
    this->loadChapter(this->currentChapterIndex + 1);
}


void re::MangaComponent::previousChapter() {
    this->loadChapter(this->currentChapterIndex - 1);
}


void re::MangaComponent::loadChapter(const std::size_t& chapterIndex) {
    if (chapterIndex < this->chapters.size()) {
        if (this->currentChapter) this->currentChapter->clear();
        this->currentChapterIndex = chapterIndex;
        this->currentChapter = this->chapters[chapterIndex];
        this->manga->lastChapterReaded = chapterIndex;
        this->currentChapter->load();
    }
}


void re::MangaComponent::load() {
    this->clear();
    for (re::Chapter* chapter : this->manga->chapters) {
        this->chapters.push_back(new re::ChapterComponent(chapter));
    }
    this->loadChapter(this->manga->lastChapterReaded);
}


void re::MangaComponent::clear() {
    if (this->currentChapter) this->currentChapter->clear();
    for (re::ChapterComponent* chapter : this->chapters)
        delete chapter;
    this->chapters.clear();
}


void re::MangaComponent::update(const double& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->previousChapter();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->nextChapter();
    this->currentChapter->update(dt);
}


void re::MangaComponent::draw(sf::RenderWindow& window) {
    this->currentChapter->draw(window);
}