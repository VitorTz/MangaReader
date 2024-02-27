#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
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
            bool is_favorite = false;
            std::size_t chapter_num = 0;
        
        public:
            explicit Manga(const std::filesystem::path& manga_dir);                      
            const std::filesystem::path& get_current_chapter_path() const; 
            
            void set_favorite(bool favorite);
            bool is_manga_favorite() const;

            const std::string& get_name() const;
            bool change_chapter_num(std::size_t index);
            std::size_t get_current_chapter_num() const;
            std::size_t get_total_num_chapters() const;
            std::filesystem::path get_cover_image() const;

    };

    typedef std::map<std::string, std::unique_ptr<mr::Manga>> MangaMap;

    void load_mangas(mr::MangaMap* manga_map);
    void dump_mangas(mr::MangaMap* manga_map);
    
} // namespace mr
