#include "../../include/util/manga.hpp"
#include <algorithm>
#include <filesystem>
#include <string>


mr::Manga::Manga(
    const std::filesystem::path& path
) : path(path),
    name(path.stem().string()) {
        std::cout << "[MANGA LOAD] [" << name << "]\n";    
        
        for (const auto& p : std::filesystem::directory_iterator(path)) {
            const std::filesystem::path path = p.path();
            if (std::filesystem::is_directory(path)) {
                chapters.push_back(p);
            }
        }

        std::sort(
            chapters.begin(), chapters.end(),
            [](const std::filesystem::path& l, const std::filesystem::path& r) {
                return std::stof(l.stem().c_str() + 8) < std::stof(r.stem().c_str() + 8);  
            }
        );

    }


std::filesystem::path mr::Manga::getCoverImagePath() const {
    std::filesystem::path cover = path.string() + '/' + "cover.jpg";
    cover = std::filesystem::exists(cover) ? cover : mr::constants::DEFAULT_COVER_IMAGE;
    return cover;
}