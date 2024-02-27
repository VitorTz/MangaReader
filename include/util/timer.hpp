#pragma once



namespace mr {


    class Timer {

        private:
            int count = 0;
            int max_count;
        
        public:
            Timer(const int frames);
            void update();
            bool check();
        
    };
    
} // namespace mr
