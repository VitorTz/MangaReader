#include "../../include/util/util.hpp"


int re::extractNum(const std::string& s) {
    std::string num = "0";
    for (const char& c : s)
        if (std::isdigit(c))
            num += c;
    return std::stoi(num);
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


std::string re::subStr(
    const std::string& s, 
    const std::size_t& start,
    const std::size_t& end
) {
    std::size_t _end = end > s.size() ? s.size() : end;
    std::string str;
    for (std::size_t i = start; i < _end; i++) 
        str += s.at(i);
    return str;
}