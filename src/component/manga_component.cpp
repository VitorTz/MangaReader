#include "../../include/component/manga_component.hpp"


re::MangaComponent::MangaComponent(
    std::shared_ptr<re::Manga> manga
) : re::Component(manga->name),
    manga(manga),
    chapters(re::dirFiles(manga->path)),
    text(manga->name + " has no chapters", {}, re::style::headerTxtStyle) {
    this->loadChapter(manga->lastChapterReaded);
    this->text.transform.setCenter(re::SCREEN_CENTER);
}


void re::MangaComponent::loadChapter(const std::size_t& n) {
    if (n < this->chapters.size()) {
        this->currentChapter.chapter.reset();
        this->currentChapter.chapter = std::make_unique<re::Chapter>(this->chapters.at(n));
        this->manga->lastChapterReaded = n;
        this->currentChapter.index = n;
    }
}


void re::MangaComponent::update(const float& dt) {
    if (this->chapters.empty())
        return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->loadChapter(this->currentChapter.index + 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->loadChapter(this->currentChapter.index - 1);
        
    if (this->currentChapter.chapter)
        this->currentChapter.chapter->update(dt);
}


void re::MangaComponent::draw(sf::RenderWindow& window) {
    if (this->currentChapter.chapter)
        this->currentChapter.chapter->draw(window);
    else    
        this->text.draw(window);
}
