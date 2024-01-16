#include "../../include/model/manga.hpp"
#include <iostream>

re::Manga::Manga(
    const std::filesystem::path& path
) : path(path),
    name(path.stem()),
    mangaCoverFile(this->getMangaCoverFile()),
    lastChapterReaded(0),
    isFavorite(false) {
    
    }



const std::filesystem::path re::Manga::getMangaCoverFile() {
    std::filesystem::path fileName1(
        this->path.string() + '/' + "cover.jpg"
    );
    std::filesystem::path fileName2(
        this->path.string() + '/' + "cover.png"
    );
    
    if (std::filesystem::exists(fileName1)) {
        return fileName1;
    } 
    if (std::filesystem::exists(fileName2)) {
        return fileName2;
    }
    return re::DEFAULT_COVER;
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