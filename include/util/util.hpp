#ifndef MANGA_READER_UTIL_HPP
#define MANGA_READER_UTIL_HPP
#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include "../util/font_pool.hpp"
#include "../constants.hpp"
#include "../font.hpp"


namespace re {

    double extractNum(const std::string& s);
    void split(const std::string& s, const char& sep, std::vector<std::string>& v);
    std::string getMangaCoverFile(const std::string& mangaName);

    std::string subStr(const std::string& s, const std::size_t& start, const std::size_t& end);
    sf::Vector2f stringSize(
        const std::string& s, 
        const std::size_t& characterSize,
        const re::FontId& fontId
    );

    template<typename T>
    void clearPtrVector(std::vector<T*>& v) {
        for (T* t : v)
            delete t;
        v.clear();
    }
    
} // namespace re


#endif