#ifndef C27A507A_C669_4CD5_8772_2196CD5EB43F
#define C27A507A_C669_4CD5_8772_2196CD5EB43F
#include <vector>
#include <memory>
#include "sprite.hpp"
#include "chapter.hpp"
#include "text.hpp"
#include "../model/manga.hpp"


namespace re {

    class MangaComponent : public re::Component {

        private:
            std::shared_ptr<re::Manga> manga;
            std::vector<std::filesystem::path> chapters;
            std::unique_ptr<re::Chapter> currentChapter;
            std::size_t currentChapterIndex;
            re::Text text;
        
        private:
            void loadChapter(const std::size_t n);
        
        public:
            MangaComponent(const std::shared_ptr<re::Manga>& manga);
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            std::size_t numChapters() const;
    };
    
} // namespace re


#endif /* C27A507A_C669_4CD5_8772_2196CD5EB43F */
