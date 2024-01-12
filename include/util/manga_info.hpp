#ifndef E7B8FFCB_391B_4104_86E6_6C5ACBEB90F1
#define E7B8FFCB_391B_4104_86E6_6C5ACBEB90F1
#include <string>

namespace re {


    typedef struct MangaInfo {
        const std::string name;
        const std::size_t lastChapterReaded;
        const bool isFavorite;
        const bool success;
    } MangaInfo;
    
} // namespace re


#endif /* E7B8FFCB_391B_4104_86E6_6C5ACBEB90F1 */
