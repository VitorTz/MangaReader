#include "../include/globals.hpp"


std::map<std::string, std::shared_ptr<re::Manga>> re::globals::mangaMap;


std::string re::globals::currentManga;


std::vector<sf::Keyboard::Key> re::globals::pressedKeys;


float re::globals::currentTime = 0;
