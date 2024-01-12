#ifndef E2E0A78C_EA1E_4F2C_B885_790ADF5CF6FF
#define E2E0A78C_EA1E_4F2C_B885_790ADF5CF6FF
#include "scene.hpp"


namespace re {


    class Library : public re::Scene {

        public:
            Library(const re::ChangeScene& changeScene);
            void update(const float& dt) override;
            
    };
    
} // namespace re


#endif /* E2E0A78C_EA1E_4F2C_B885_790ADF5CF6FF */
