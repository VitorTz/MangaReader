#ifndef MANGA_READER_LIBRARY_HPP
#define MANGA_READER_LIBRARY_HPP
#include "scene.hpp"



namespace re {


    class Library : public re::Scene {

        public:
            Library(const re::ChangeScene& changeScene);
            void update(const double dt) override;

    };
    
} // namespace re




#endif