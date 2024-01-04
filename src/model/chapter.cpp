#include "../../include/model/chapter.hpp"


re::Chapter::Chapter(
    const std::filesystem::path& path
) : path(path),
    name(path.stem().string()),
    num(re::extractNum(path.stem().string())) {

    }


re::Chapter::~Chapter() {
    re::clearPtrVector(this->images);
}


void re::Chapter::loadImages() {
    for (const auto& p : std::filesystem::directory_iterator(this->path)) {
        this->images.push_back(new re::Image(p.path()));
    }
    std::sort(
        this->images.begin(), 
        this->images.end(),
        [](re::Image* img1, re::Image* img2) { return img1->num < img2->num; }      
    );
}


void re::Chapter::clearImages() {
    re::clearPtrVector(this->images);
}