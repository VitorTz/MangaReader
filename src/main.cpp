#include "../include/window/window.hpp"
#include "../include/nlohmann/json.hpp"
#include <fstream>


nlohmann::json getJson(const std::filesystem::path& filePath) {
    std::ifstream jsonFile(filePath);
    nlohmann::json jsonData = nlohmann::json::parse(jsonFile);
    return jsonData;
}


void init() {

    nlohmann::json settings = getJson(re::SETTINGS_FILE);
    std::filesystem::path mangaFolder(settings["main_folder"]);

    for (const auto& mangaPath : std::filesystem::directory_iterator(mangaFolder)) {
        const std::filesystem::path& path = mangaPath.path();
        re::globals::mangaByName.insert(
            {
                path.stem().string(),
                std::make_shared<re::Manga>(path)
            }
        );
    }

    nlohmann::json mangas = getJson(re::MANGAS_FILE);
    for (const auto& mangaInfo : mangas) {
        const std::string& name = mangaInfo["name"];
        try {
            std::shared_ptr<re::Manga>& m = re::globals::mangaByName.at(name);
            m->deserialize(mangaInfo);            
        } catch (std::out_of_range& e) {
            std::cout << "Manga " << name << " not fond\n";
        }
    }

}


void close() {
    nlohmann::json jsonData;
    
    for (auto& [name, manga] : re::globals::mangaByName) {
        manga->serialize(jsonData);
    }
    
    std::ofstream jsonFile(re::MANGAS_FILE);
    jsonFile << std::setw(4) << jsonData;

    re::TexturePool::rmvAll();
    re::FontPool::rmvAll();
}


int main() {
    init();
    re::Window w;
    w.run();
    close();
    return EXIT_SUCCESS;
}
