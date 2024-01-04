#include "../../include/util/timer.hpp"



re::Timer::Timer(
    const double& timeInSeconds
) : currentTime(0),
    timeInSeconds(timeInSeconds) {

}


bool re::Timer::check(const double dt) {
    this->currentTime += dt;
    const bool status = this->currentTime >= this->timeInSeconds;
    if (status) this->currentTime = 0;
    return status;
} 