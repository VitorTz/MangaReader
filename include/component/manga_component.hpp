#ifndef C27A507A_C669_4CD5_8772_2196CD5EB43F
#define C27A507A_C669_4CD5_8772_2196CD5EB43F
#include <vector>
#include <memory>
#include "component.hpp"
#include "sprite.hpp"
#include "chapter.hpp"
#include "text.hpp"
#include "../model/manga.hpp"


namespace re {

    typedef struct CurrentChapter {
        std::unique_ptr<re::Chapter> chapter;
        std::size_t index;
    } CurrentChapter;

    class MangaComponent : public re::Component {

        private:
            std::shared_ptr<re::Manga> manga;
            std::vector<std::string> chapters;
            re::CurrentChapter currentChapter;
            re::Text text;
        
        private:
            void loadChapter(const std::size_t& n);
        
        public:
            MangaComponent(std::shared_ptr<re::Manga> manga);
            void update(const float& dt) override;
            void draw(sf::RenderWindow& window) override;
    };
    
} // namespace re


#endif /* C27A507A_C669_4CD5_8772_2196CD5EB43F */
