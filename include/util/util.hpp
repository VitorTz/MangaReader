#pragma once
#include <map>
#include <cctype>
#include <vector>
#include <string>
#include <filesystem>


namespace re {

    int extractNum(const std::string& s);

    void split(const std::string& s, const char& sep, std::vector<std::string>& v);

    std::string subStr(
        const std::string& s, 
        const std::size_t& start,
        const std::size_t& end
    );

    template<typename K, typename V>
    void deletePtrMap(std::map<K, V*>& v) {
        for (const auto& pair : v) {
            delete pair.second;
        }
        v.clear();       
    }

    template<typename T>
    void deletePtrVector(std::vector<T*>& v) {
        for (T* t : v)
            delete t;
        v.clear();
    }

    
} // namespace re

