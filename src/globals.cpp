#include "../include/globals.hpp"


std::map<std::string, std::shared_ptr<re::Manga>> re::mangaMap;


std::string re::currentManga = "";


std::vector<sf::Keyboard::Key> re::pressedKeys;


float re::currentTime = 0;


bool re::hasFocus = false;
