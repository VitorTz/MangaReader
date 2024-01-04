#ifndef MANGA_READER_HPP
#define MANGA_READER_HPP
#include <string>
#include <map>



namespace re {


    enum class FontId {
        Regular,
        Light,
        SemiBold,
        Bold
    };

    const std::map<re::FontId, std::string> fontPathById = {
        {re::FontId::Light, "res/font/Roboto-Thin.ttf"},
        {re::FontId::Regular, "res/font/Roboto-Regular.ttf"},
        {re::FontId::SemiBold, "res/font/Roboto-Medium.ttf"},
        {re::FontId::Bold, "res/font/Roboto-Bold.ttf"}
    };
    
} // namespace re


#endif