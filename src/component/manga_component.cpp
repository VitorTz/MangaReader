#include "../../include/component/manga_component.hpp"


re::MangaComponent::MangaComponent(
    const std::shared_ptr<re::Manga>& manga
) : re::Component(manga->name),
    manga(manga),
    text(manga->name + " has no chapters", re::style::headerTxtStyle) {
    for (const std::filesystem::path& p : re::dirFiles(manga->path)) {
        if (std::filesystem::is_directory(p))
            this->chapters.push_back(p);
    }
    this->loadChapter(manga->lastChapterReaded);
    this->text.transform.setCenter(re::SCREEN_CENTER);
}


void re::MangaComponent::loadChapter(const std::size_t n) {
    if (n < this->chapters.size()) {
        this->manga->lastChapterReaded = n;
        this->currentChapter = std::make_unique<re::Chapter>(this->chapters.at(n));
    }
}


void re::MangaComponent::update(const float dt) {
    if (this->chapters.empty())
        return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->loadChapter(this->manga->lastChapterReaded + 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->loadChapter(this->manga->lastChapterReaded - 1);
        
    if (this->currentChapter) {
        this->currentChapter->update(dt);
    }
}


void re::MangaComponent::draw(sf::RenderWindow& window) {
    if (this->currentChapter)
        this->currentChapter->draw(window);
    else    
        this->text.draw(window);
}


std::size_t re::MangaComponent::numChapters() const {
    return this->chapters.size();
}