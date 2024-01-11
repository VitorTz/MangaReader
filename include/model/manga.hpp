#ifndef E1FD90DE_EA3F_4B81_B8E0_D06C727957C4
#define E1FD90DE_EA3F_4B81_B8E0_D06C727957C4
#include <string>
#include <filesystem>
#include "../util/util.hpp"


namespace re {


    class Manga {

        public:
            const std::filesystem::path path;
            const std::string name;
            const std::string mangaCoverFile;
            std::size_t lastChapterReaded;
            bool isFavorite;
        
        public:
            Manga(const std::filesystem::path& path); 

    };
    
} // namespace re


#endif /* E1FD90DE_EA3F_4B81_B8E0_D06C727957C4 */
