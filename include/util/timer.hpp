#ifndef A4E2EADF_CD81_49A8_851D_CAD303B1A3EA
#define A4E2EADF_CD81_49A8_851D_CAD303B1A3EA
#include <SFML/System/Clock.hpp>

namespace re {


    class Timer {

        private:
            sf::Clock clock;
            float startedTime;
            float timeInSeconds;
            bool m_is_running;

        public:
            explicit Timer(const float timeInSeconds);            
            void reset();
            bool isRunning();
    };
    
} // namespace re


#endif /* A4E2EADF_CD81_49A8_851D_CAD303B1A3EA */
