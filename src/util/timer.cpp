#include "../../include/util/timer.hpp"



mr::Timer::Timer(
    const int frames
) : max_count(frames) {

}


void mr::Timer::update() {
    ++count;
}


bool mr::Timer::check() {
    const bool s = count >= max_count;
    if (s) {
        count = 0;
    }
    return s;
}