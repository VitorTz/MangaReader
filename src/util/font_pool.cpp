#include "../../include/util/font_pool.hpp"


std::map<re::FontId, sf::Font*> re::FontPool::fonts;


sf::Font* re::FontPool::get(const re::FontId& fontId) {
    if (re::FontPool::fonts.find(fontId) == re::FontPool::fonts.end()) {
        sf::Font* f = new sf::Font();
        f->loadFromFile(re::fontPathById.at(fontId));
        re::FontPool::fonts.insert({fontId, f});
    }
    return re::FontPool::fonts.at(fontId);
}


void re::FontPool::rmv(const re::FontId& fontId) {
    if (re::FontPool::fonts.find(fontId) != re::FontPool::fonts.end()) {
        sf::Font* f = re::FontPool::fonts.at(fontId);
        re::FontPool::fonts.erase(fontId);
        delete f;
    }
}


void re::FontPool::rmvAll() {
    for (const auto& pair : re::FontPool::fonts)
        delete pair.second;
}