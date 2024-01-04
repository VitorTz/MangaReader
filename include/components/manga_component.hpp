#pragma once
#include "component.hpp"
#include "chapter_component.hpp"


namespace re {

    class MangaComponent : public re::Component {

        private:
            re::Manga* manga;
            re::ChapterComponent* currentChapter;
        
        private:
            void changeChapter(const std::size_t& index);

        public:
            MangaComponent(re::Manga* manga);
            ~MangaComponent() override;
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace re
