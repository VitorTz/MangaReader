#include "../../include/util/timer.hpp"



re::Timer::Timer(
    const float& timeInSeconds
) : startedTime(re::currentTime),
    timeInSeconds(timeInSeconds),
    _isRunning(false) {

    }


void re::Timer::start() {
    this->_isRunning = true;
    this->startedTime = re::currentTime;
}


void re::Timer::update() {
    if (this->_isRunning)
        this->_isRunning = !(re::currentTime - this->startedTime >= this->timeInSeconds);        
}


void re::Timer::reset() {
    this->startedTime = re::currentTime;
    this->start();
}


bool re::Timer::isRunning() const {
    return this->_isRunning;
}