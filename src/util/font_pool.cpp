#include "../../include/util/font_pool.hpp"

  
std::map<re::FontId, std::unique_ptr<sf::Font>> re::FontPool::fonts;


void re::FontPool::load(sf::Text& t, const re::FontId& f) {
    if (re::FontPool::fonts.find(f) == re::FontPool::fonts.end()) {
        const auto& [pair, success] = re::FontPool::fonts.insert({f, std::make_unique<sf::Font>()});
        pair->second->loadFromFile(re::fontPathById.at(f));
    }
    auto& font = re::FontPool::fonts.at(f);
    t.setFont(*font);
}


void re::FontPool::rmv(const re::FontId& f) {
    if (re::FontPool::fonts.find(f) != re::FontPool::fonts.end()) {
        re::FontPool::fonts.erase(f);
    }
}


void re::FontPool::rmvAll() {
    re::FontPool::fonts.clear();
}