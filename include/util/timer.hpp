#ifndef A4E2EADF_CD81_49A8_851D_CAD303B1A3EA
#define A4E2EADF_CD81_49A8_851D_CAD303B1A3EA
#include "../globals.hpp"


namespace re {


    class Timer {

        private:
            float startedTime;
            float timeInSeconds;
            bool _isRunning;

        public:
            Timer(const float& timeInSeconds);
            void update();
            void start();
            void reset();
            bool isRunning() const;
    };
    
} // namespace re


#endif /* A4E2EADF_CD81_49A8_851D_CAD303B1A3EA */
