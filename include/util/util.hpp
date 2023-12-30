#ifndef MANGA_READER_UTIL_HPP
#define MANGA_READER_UTIL_HPP
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <filesystem>


namespace og {

    std::vector<std::string>* getFiles(const std::string& dir);
    std::vector<std::string>* split(const std::string& s, const char& sep);
    std::vector<std::string>* split(const std::string& s);
    double extractNumber(const std::string& s);

    
} // namespace og


#endif