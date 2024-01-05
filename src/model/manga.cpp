#include "../../include/model/manga.hpp"


re::Manga::Manga(
    const std::filesystem::path& _path 
) : path(_path.string()),
    name(_path.stem()),
    coverImagePath(re::getCoverFile(name)),
    lastChapterReaded(0),
    isFavorite(false) {
        for (const auto& p : std::filesystem::directory_iterator(_path)) {
            this->chapters.push_back(new re::Chapter(p.path()));
        }
        std::sort(
            this->chapters.begin(),
            this->chapters.end(),
            [](re::Chapter* c1, re::Chapter* c2) { return c1->num < c2->num; }
        );
    }

re::Manga::~Manga() {
    for (re::Chapter* c : this->chapters)
        delete c;
}


std::string re::Manga::toString() const {
    return this->name + '-' + std::to_string(this->lastChapterReaded) + '-' + std::to_string((int) this->isFavorite);
}


std::string re::getCoverFile(const std::string& mangaName) {
    const std::string filePath = re::constants::MANGA_COVER_DIR + '/' + mangaName + ".png";
    std::filesystem::path path(filePath);
    if (std::filesystem::exists(path)) {
        return filePath;
    }
    return re::constants::DEFAULT_COVER_FILE;
}