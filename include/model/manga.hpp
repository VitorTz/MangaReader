#ifndef E1FD90DE_EA3F_4B81_B8E0_D06C727957C4
#define E1FD90DE_EA3F_4B81_B8E0_D06C727957C4
#include <filesystem>
#include <string>
#include <vector>
#include "../constants.hpp"
#include "../util/util.hpp"
#include "../nlohmann/json.hpp"


namespace re {


    class Manga {

        public:
            const std::filesystem::path path;
            const std::string name;
            const std::string mangaCoverFile;
            const std::size_t numChapters;
            std::size_t lastChapterReaded;
            bool isFavorite;
        
        private:
            const std::filesystem::path getMangaCoverFile();
        
        public:
            Manga(const std::filesystem::path& path);
            void changeFavoriteStatus();
            void deserialize(const nlohmann::json& json);
            void serialize(nlohmann::json& json);

    };
    
} // namespace re


#endif /* E1FD90DE_EA3F_4B81_B8E0_D06C727957C4 */
