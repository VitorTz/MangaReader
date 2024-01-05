#pragma once
#include <cctype>

namespace re {

    class Timer {

        private:
            std::size_t currentFrame;
            const std::size_t frames;

        public:
            Timer(const std::size_t& countFrame);
            bool check();

    };
    
} // namespace re
