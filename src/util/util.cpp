#include "../../include/util/util.hpp"


std::vector<std::string>* og::getFiles(const std::string& s) {
    std::filesystem::path path(s);

    std::vector<std::pair<double, std::string>> filesPair;
    for (auto& p : std::filesystem::directory_iterator(path)) {
        const std::string name = p.path().string();
        const double num = og::extractNumber(name);
        filesPair.push_back({num, name});
    }
    std::sort(filesPair.begin(), filesPair.end());

    std::vector<std::string>* v = new std::vector<std::string>();
    for (auto& pair : filesPair)
        v->push_back(pair.second);
    
    return v;
}


std::vector<std::string>* og::split(const std::string& s, const char& sep) {
    std::vector<std::string>* v = new std::vector<std::string>();
    std::string str;
    for (const char& c : s)
        if (c == sep && !str.empty()) {
            v->push_back(str);
            str.clear();
        } else {
            str += c;
        }
        
    if (!str.empty()) v->push_back(str);

    return v;
}


std::vector<std::string>* og::split(const std::string& s) {
    return og::split(s, ' ');
}


double og::extractNumber(const std::string& s) {
    std::string num = "0";
    bool start = false;
    for (const char& c : s) {
        const bool isDigit = std::isdigit(c);
        const bool isDot = c == '.';
        if (!start && isDigit)  
            start = true;
        if (start && (isDigit || isDot))
            num += c;
    }
    return std::stod(num);
}