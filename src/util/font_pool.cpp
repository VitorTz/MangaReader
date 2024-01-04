#include "../../include/util/font_pool.hpp"


std::map<re::Font::FontId, sf::Font*> re::Font::FontPool::fonts;


sf::Font* re::Font::FontPool::get(const re::Font::FontId& fontId) {
    if (re::Font::FontPool::fonts.find(fontId) == re::Font::FontPool::fonts.end()) {
        sf::Font* f = new sf::Font();
        f->loadFromFile(re::Font::fontPathById.at(fontId));
        re::Font::FontPool::fonts.insert({fontId, f});
    }
    return re::Font::FontPool::fonts.at(fontId);
}


void re::Font::FontPool::rmv(const re::Font::FontId& fontId) {
    if (re::Font::FontPool::fonts.find(fontId) != re::Font::FontPool::fonts.end()) {
        sf::Font* f = re::Font::FontPool::fonts.at(fontId);
        delete f;
        re::Font::FontPool::fonts.erase(fontId);
    }
}


void re::Font::FontPool::rmvAll() {
    for (const auto& pair : re::Font::FontPool::fonts)
        delete pair.second;
}


sf::Vector2f re::Font::getStrSize(const std::string& s, const std::size_t& characterSize, const re::Font::FontId& fontId) {
    sf::Text t;
    sf::Font* f = re::Font::FontPool::get(fontId);
    t.setString(s);
    t.setFont(*f);
    t.setCharacterSize(characterSize);
    sf::FloatRect size = t.getLocalBounds();
    return {size.width, size.height};
}