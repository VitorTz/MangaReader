#ifndef C29C0935_71F5_4385_B84E_0B84D1930A87
#define C29C0935_71F5_4385_B84E_0B84D1930A87
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <cctype>
#include <filesystem>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <map>
#include "../constants.hpp"


namespace re {
    
    std::vector<std::filesystem::path> dirFiles(const std::filesystem::path& path);
    float extractNumFromStr(const std::string& s, const float& defaultValue);
    std::vector<std::string> split(const std::string& s, const char& sep);
    

    template<typename T>
    void printVector(const sf::Vector2<T>& v) {
        std::cout << "Vector(" << 
        std::to_string(v.x) << 
        ", " << 
        v.y << 
        ")\n";
    }

    template<typename K, typename V>
    bool contains(const std::map<K, V>& m, const K& k) {
        return m.find(k) != m.end();
    }


} // namespace re




#endif /* C29C0935_71F5_4385_B84E_0B84D1930A87 */
