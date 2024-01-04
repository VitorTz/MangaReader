#ifndef MANGA_READER_MANGA_COMPONENT_HPP
#define MANGA_READER_MANGA_COMPONENT_HPP
#include "component.hpp"
#include "chapter_component.hpp"


namespace re {

    class MangaComponent : public re::Component {

        private:
            re::Manga* manga;
            std::vector<re::ChapterComponent*> chapters;
            re::ChapterComponent* currentChapter;
            std::size_t currentChapterIndex;
        
        private:
            void nextChapter();
            void previousChapter();
            void loadChapter(const std::size_t& chapterIndex);
        

        public:
            MangaComponent(re::Manga* manga);
            ~MangaComponent() override;
            void load();
            void clear();
            void update(const double& dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re


#endif