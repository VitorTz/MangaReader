#include "../../include/model/image.hpp"

re::Image::Image(
    const std::filesystem::path& _path
) : path(_path.string()),
    num(re::extractNum(_path.stem().string())) {

    }