#ifndef D86E26C6_D3EE_4577_AD49_14C21F0C0274
#define D86E26C6_D3EE_4577_AD49_14C21F0C0274
#include "scene.hpp"


namespace re {

    class Reader : public re::Scene {

        public:
            Reader(const re::ChangeScene& changeScene);
            void update(const float& dt) override;
            
    };
    
} // namespace re


#endif /* D86E26C6_D3EE_4577_AD49_14C21F0C0274 */
