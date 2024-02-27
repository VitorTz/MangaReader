#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include "util/util.hpp"
#include "constants.hpp"


namespace mr {


    class Manga {

        private:
            std::string name;
            std::filesystem::path path;
            std::vector<std::filesystem::path> chapters; 
            std::size_t chapter_num = 0;
        
        public:
            explicit Manga(const std::filesystem::path& manga_dir);                      
            std::size_t get_current_chapter_num() const;
            const std::filesystem::path& get_current_chapter_path() const; 
            bool change_chapter_num(std::size_t index);
            const std::string& get_name() const;
            std::filesystem::path get_cover_image() const;

    };

    typedef std::map<std::string, std::unique_ptr<mr::Manga>> MangaMap;

    void load_mangas(mr::MangaMap* manga_map);
    
} // namespace mr
