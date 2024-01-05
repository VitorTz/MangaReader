#include "../../include/util/timer.hpp"


re::Timer::Timer(
    const std::size_t& frameCount
) : currentFrame(0),
    frames(frameCount) {

    }


bool re::Timer::check() {
    this->currentFrame += 1;
    const bool s = this->currentFrame >= this->frames;
    if (s) this->currentFrame = 0;
    return s;
}