#ifndef EC82ECAB_D022_4804_9E7B_52C1B09DAC5D
#define EC82ECAB_D022_4804_9E7B_52C1B09DAC5D
#include <map>
#include <memory>
#include <string>
#include <set>
#include <SFML/Window/Keyboard.hpp>
#include "model/manga.hpp"


namespace re::globals {

    extern std::map<std::string, std::shared_ptr<re::Manga>> mangaByName;
    extern std::string currentManga;
    extern std::set<sf::Keyboard::Key> pressedKeys;
    extern float currentTime;
    
} // namespace re


#endif /* EC82ECAB_D022_4804_9E7B_52C1B09DAC5D */
