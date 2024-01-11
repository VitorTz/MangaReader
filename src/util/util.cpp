#include "../../include/util/util.hpp"


std::vector<std::string> re::dirFiles(const std::string& dir) {
    return re::dirFiles(std::filesystem::path(dir));
}


std::vector<std::string> re::dirFiles(const std::filesystem::path& path) {
    std::vector<std::string> v;
    for (const auto& p : std::filesystem::directory_iterator(path))
        v.push_back(p.path().string());
    std::sort(
        v.begin(),
        v.end(),
        [](const std::string& s1, const std::string& s2) {
            const float d = std::numeric_limits<float>::max();
            return re::extractNum(s1, d) < re::extractNum(s2, d);
        }
    );
    return v;
}

float re::extractNum(const std::string& s, const float& defaultValue) {
    std::string num;
    bool start = false;
    for (const char& c : s) {
        const bool isDigit = std::isdigit(c);
        const bool isDot = c == '.';
        if (!start && isDigit)
            start = true;
        if (start && (isDigit || isDot))
            num += c;
    }
    if (!num.empty()) return std::stof(num);
    return defaultValue;
}


std::vector<std::string> re::split(const std::string& s, const char& sep) {
    std::string str;
    std::vector<std::string> v;
    for (const char& c : s) {
        if (c == sep && !str.empty()) {
            v.push_back(str);
            str.clear();
        } else {
            str += c;
        }
    }
    if (!str.empty()) v.push_back(str);
    return v;
}


std::string re::getMangaCoverImg(const std::string& mangaName) {
    const std::string fileName = re::MANGA_COVER_DIR + '/' + mangaName + ".png";
    if (std::filesystem::exists(std::filesystem::path(fileName)))
        return fileName;
    return re::DEFAULT_MANGA_COVER;
}