#pragma once


namespace mr {


    class Timer {

        private:
            const int max_frames;
            int frames = 0;
        
        public:
            Timer(int frames);
            void update();
            bool check();

    };

}