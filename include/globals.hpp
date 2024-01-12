#ifndef EC82ECAB_D022_4804_9E7B_52C1B09DAC5D
#define EC82ECAB_D022_4804_9E7B_52C1B09DAC5D
#include <map>
#include <memory>
#include <string>
#include <SFML/Window/Keyboard.hpp>
#include "model/manga.hpp"


namespace re {

    extern std::map<std::string, std::shared_ptr<re::Manga>> mangaMap;
    extern std::string currentManga;
    extern std::vector<sf::Keyboard::Key> pressedKeys;
    extern float currentTime;
    extern bool hasFocus;
    
} // namespace re


#endif /* EC82ECAB_D022_4804_9E7B_52C1B09DAC5D */
