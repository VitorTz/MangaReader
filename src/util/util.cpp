#include "../../include/util/util.hpp"


std::vector<std::filesystem::path> re::dirFiles(const std::filesystem::path& path) {
    std::vector<std::filesystem::path> v;
    for (const auto& p : std::filesystem::directory_iterator(path))
        v.push_back(p.path());
    std::sort(
        v.begin(),
        v.end(),
        [](const std::filesystem::path& s1, const std::filesystem::path& s2) {
            const float d = std::numeric_limits<float>::max();
            return re::extractNumFromStr(s1.string(), d) < re::extractNumFromStr(s2.string(), d);
        }
    );
    return v;
}

float re::extractNumFromStr(const std::string& s, const float& defaultValue) {
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


