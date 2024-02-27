#include "../include/manga.hpp"


mr::Manga::Manga(
    const std::filesystem::path& manga_dir
) : name(manga_dir.stem().string()),
    path(manga_dir),
    chapters(mr::get_chapters_from_dir(manga_dir)) {    
    std::cout << "[MANGA LOAD] [" << name << "] [" << chapters.size() << " CHAPTERS]\n";
}


const std::filesystem::path& mr::Manga::get_current_chapter_path() const {
    return chapters[chapter_num];
}


bool mr::Manga::change_chapter_num(const std::size_t index) {
    if (index >= 0 && index < chapters.size()) {
        chapter_num = index;
        return true;
    }
    return false;
}


std::size_t mr::Manga::get_current_chapter_num() const {   
    return chapter_num;
}


std::filesystem::path mr::Manga::get_cover_image() const {
    std::filesystem::path aux = path.string() + "cover.jpg";
    std::filesystem::path r = std::filesystem::exists(aux) ? aux : std::filesystem::path(mr::constants::DEFAULT_MANGA_COVER_IMAGE);
    return r;
}


const std::string& mr::Manga::get_name() const {
    return name;
}


void mr::load_mangas(mr::MangaMap* manga_map) {
    for (const auto& p : std::filesystem::directory_iterator(mr::constants::MANGA_DIR)) {
        const std::filesystem::path path = p.path();
        if (std::filesystem::is_directory(path)) {
            std::unique_ptr<mr::Manga> manga = std::make_unique<mr::Manga>(path);
            manga_map->insert({manga->get_name(), std::move(manga)});
        }
    }
}