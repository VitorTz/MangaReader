#ifndef MANGA_READER_UTIL_HPP
#define MANGA_READER_UTIL_HPP
#include <filesystem>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>


namespace re {

    double extractNum(const std::string& s);
    void split(const std::string& s, const char& sep, std::vector<std::string>& v);
    void saveMangaSettings();
    
} // namespace re


#endif