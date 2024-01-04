#include "../../include/model/chapter.hpp"


re::Chapter::Chapter(
    const std::filesystem::path& _path
) : path(_path.string()),
    name(_path.stem()),
    num(re::extractNum(name)) {

    }


re::Chapter::~Chapter() {
    this->clearImages();
}

void re::Chapter::clearImages() {
    for (re::Image* image : this->images)
        delete image;
    this->images.clear();
}



void re::Chapter::loadImages() {
    this->clearImages();
    std::filesystem::path _path(this->path);
    for (const auto& p : std::filesystem::directory_iterator(_path))
        this->images.push_back(new re::Image(p.path()));
    
    std::sort(
        this->images.begin(),
        this->images.end(),
        [](re::Image* i1, re::Image* i2) { return i1->num < i2->num; }
    );
}