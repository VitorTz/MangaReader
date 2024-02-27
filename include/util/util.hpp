#pragma once
#include <filesystem>
#include <vector>
#include <algorithm>


namespace mr {
    
    std::vector<std::filesystem::path> get_chapters_from_dir(const std::filesystem::path& dir);
    std::vector<std::filesystem::path> get_images_files_from_dir(const std::filesystem::path& dir);
    std::vector<std::string> split(const std::string& s, const char sep);

} // namespace mr
