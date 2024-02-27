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


bool mr::Manga::is_manga_favorite() const {
    return is_favorite;
}


void mr::Manga::set_favorite(const bool favorite) {
    is_favorite = favorite;
}


std::size_t mr::Manga::get_total_num_chapters() const {
    return chapters.size();
}


void mr::load_mangas(mr::MangaMap* manga_map) {
    for (const auto& p : std::filesystem::directory_iterator(mr::constants::MANGA_DIR)) {
        const std::filesystem::path path = p.path();
        if (std::filesystem::is_directory(path)) {
            std::unique_ptr<mr::Manga> manga = std::make_unique<mr::Manga>(path);
            manga_map->insert({manga->get_name(), std::move(manga)});
        }
    }
    
    std::filesystem::create_directory(mr::constants::SETTINGS_DIR);
    std::ifstream manga_file;
    manga_file.open(mr::constants::MANGAS_TXT_FILE, std::fstream::in);
    std::string line;
    bool start = false;
    if (manga_file.is_open()) {
        while (std::getline(manga_file, line)) {
            std::vector<std::string> manga_info = mr::split(line, ' ');
            const std::string name = manga_info[0];
            const std::size_t last_chapter = std::stoi(manga_info[1]);
            const bool is_favorite = manga_info[2] == "1";
            if (manga_map->find(name) == manga_map->end()) {
                std::cout << "[MANGA " << name << " NOT FOND]\n";
                continue;
            }
            mr::Manga* manga = manga_map->at(name).get();
            manga->change_chapter_num(last_chapter);
            manga->set_favorite(is_favorite);
        }
        manga_file.close();
    }

}


void mr::dump_mangas(mr::MangaMap* manga_map) {    
    std::ofstream file;
    file.open(mr::constants::MANGAS_TXT_FILE);
    if (file.is_open()) {
        for (const auto& [manga_name, manga] : *manga_map) {
            const std::string line = manga_name + ' ' + std::to_string(manga->get_current_chapter_num()) + ' ' + std::to_string(manga->is_manga_favorite()) + '\n';
            file << line;
        }
        file.close();
    }
}