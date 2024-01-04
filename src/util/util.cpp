#include "../../include/util/util.hpp"



double re::extractNum(const std::string& s) {
    std::string num = "0";    
    for (const char& c : s)
        if (std::isdigit(c) || c == '.')
            num += c;
    return std::stod(num);
}


void re::split(const std::string& s, const char& sep, std::vector<std::string>& v) {
    std::string str;
    for (const char& c : s) {
        if (c == sep && !str.empty()) {
            v.push_back(str);
            str.clear();
        } else {
            str += c;
        }
    }
    if (!str.empty()) v.push_back(str);
}



std::string re::getMangaCoverFile(const std::string& mangaName) {
    const std::string filePath = re::MANGA_COVER_DIR + '/' + mangaName;
    std::filesystem::path p(filePath);
    if (!std::filesystem::exists(p))
        return re::DEFAULT_MANGA_COVER;
    return filePath;
}


sf::Vector2f re::stringSize(
    const std::string& s, 
    const std::size_t& characterSize,
    const re::FontId& fontId
) {
    sf::Text t;
    sf::Font* f = re::FontPool::get(fontId);
    t.setCharacterSize(characterSize);
    t.setFont(*f);
    t.setString(s);
    const sf::FloatRect& size = t.getLocalBounds();
    return {size.width, size.height};
}


std::string re::subStr(const std::string& s, const std::size_t& start, const std::size_t& end) {
    std::string r;
    for (std::size_t i = start; i < end; i++ ) {
        r += s.at(i);
    }
    return r;
}