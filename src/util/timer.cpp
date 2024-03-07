#include "../../include/util/timer.hpp"


mr::Timer::Timer(
    const int frames
) : max_frames(frames) {

}


void mr::Timer::update() {
    ++frames;
}


bool mr::Timer::check() {
    const bool s = frames >= max_frames;
    if (s) frames = 0;
    return s;
}