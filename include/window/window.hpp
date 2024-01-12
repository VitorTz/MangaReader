#ifndef C7997E6A_D1C7_4985_A378_347C722CF0F8
#define C7997E6A_D1C7_4985_A378_347C722CF0F8
#include "../scene/scenes.hpp"
#include "../util/notification_manager.hpp"


namespace re {

    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<re::Scene> scene;
            re::ChangeScene changeScene;
        
        private:
            void handleInput();
            void update();
            void draw();

        public:
            Window();
            void run();

    };
    
} // namespace re


#endif /* C7997E6A_D1C7_4985_A378_347C722CF0F8 */
