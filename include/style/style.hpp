#ifndef CE803B96_3FBA_4CD5_A695_05E686032805
#define CE803B96_3FBA_4CD5_A695_05E686032805
#include "../constants.hpp"


namespace re::style {

    
    typedef struct TextStyle {
        const re::FontId font;
        const std::size_t size;
        const sf::Color color;
    } TextStyle;


    const re::style::TextStyle gridItemTxtStyle{
        re::FontId::Regular,
        16,
        sf::Color::White
    };

    const re::style::TextStyle notificationTxtStyle{
        re::FontId::Medium,
        14,
        sf::Color::White
    };

    const re::style::TextStyle headerTxtStyle{
        re::FontId::Bold,
        20,
        sf::Color::White
    };
    
} // namespace re::style


#endif /* CE803B96_3FBA_4CD5_A695_05E686032805 */
