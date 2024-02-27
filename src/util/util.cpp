#include "../../include/util/util.hpp"



std::vector<std::filesystem::path> mr::get_chapters_from_dir(const std::filesystem::path& dir) {
    std::vector<std::filesystem::path> v;
    for (const auto& p : std::filesystem::directory_iterator(dir)) {
        v.push_back(p.path());
    }
    std::sort(
        v.begin(), v.end(),
        [](const std::filesystem::path& l, const std::filesystem::path& r) {
            return std::stof(l.stem().string().c_str() + 8) < std::stof(r.stem().string().c_str() + 8);                    
        }
    ); 
    return v;
}


std::vector<std::filesystem::path> mr::get_images_files_from_dir(const std::filesystem::path& dir) {
    std::vector<std::filesystem::path> v;
    for (const auto& p : std::filesystem::directory_iterator(dir)) {
        v.push_back(p.path());
    }
    std::sort(
        v.begin(), v.end(),
        [](const std::filesystem::path& l, const std::filesystem::path& r) {
            return std::stoi(l.stem().string()) < std::stoi(r.stem().string());
        }
    );
    return v;
}