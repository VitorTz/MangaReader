#include "../../include/model/manga.hpp"


re::Manga::Manga(
    const std::filesystem::path& path
) : path(path),
    name(path.stem()),
    mangaCoverFile(re::getMangaCoverImg(name)),
    lastChapterReaded(0),
    isFavorite(false) {
    
    }

