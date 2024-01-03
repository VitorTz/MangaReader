#include "../../include/model/image.hpp"


re::Image::Image(
    const std::filesystem::path& path
) : path(path),
    name(path.string()),
    num(re::extractNum(path.stem().string())) {

    }


re::Image::~Image() {
    re::ImagePool::rmv(this->name);
}