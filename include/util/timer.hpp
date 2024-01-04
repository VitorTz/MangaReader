#ifndef MANGA_READER_TIMER_HPP
#define MANGA_READER_TIMER_HPP



namespace re {

    class Timer {

        private:
            double currentTime;
            double timeInSeconds;

        public:
            Timer(const double& timeInSeconds);
            bool check(const double dt);
            
    };
    
} // namespace re


#endif