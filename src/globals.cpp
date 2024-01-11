#include "../include/globals.hpp"


std::map<std::string, std::shared_ptr<re::Manga>> re::mangaMap;


std::string re::currentManga = "Secret Class";


std::vector<sf::Keyboard::Key> re::pressedKeys;