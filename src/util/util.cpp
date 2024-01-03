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

