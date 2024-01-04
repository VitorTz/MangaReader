#include "../../include/model/manga.hpp"


re::Manga::Manga(
    const std::filesystem::path& path
) : path(path),
    name(path.stem().string()),
    coverImagePath(re::getMangaCoverFile(this->name)),
    lastChapterReaded(0),
    isFavorite(false) {
        for (const auto& p : std::filesystem::directory_iterator(this->path)) {            
            this->chapters.push_back(new re::Chapter(p.path()));
        }
        std::sort(
            this->chapters.begin(),
            this->chapters.end(),
            [](re::Chapter* c1, re::Chapter* c2) {return c1->num < c2->num; }
        );
    }


re::Manga::~Manga() {
    re::clearPtrVector(this->chapters);
}