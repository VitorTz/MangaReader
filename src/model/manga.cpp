#include "../../include/model/manga.hpp"


re::Manga::Manga(
    const std::filesystem::path& path
) : path(path),
    name(path.stem()),
    mangaCoverFile(this->getMangaCoverFile()),
    numChapters(re::countDir(path)), 
    lastChapterReaded(0),
    isFavorite(false) {
        
        
    }



const std::filesystem::path re::Manga::getMangaCoverFile() {
    std::filesystem::path fileName(this->path.string() + '/' + "cover.jpg");
    return std::filesystem::exists(fileName) ? fileName : re::DEFAULT_COVER;    
}



void re::Manga::changeFavoriteStatus() {
    this->isFavorite = !this->isFavorite;
}


void re::Manga::deserialize(const nlohmann::json& json) {
    this->isFavorite = json["isFavorite"];
    this->lastChapterReaded = json["lastChapterReaded"];
}


void re::Manga::serialize(nlohmann::json& json) {
    json[this->name] = {
        {"name", this->name},
        {"isFavorite", this->isFavorite},
        {"lastChapterReaded", this->lastChapterReaded}
    };
}