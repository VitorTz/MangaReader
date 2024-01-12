#include "../../include/util/timer.hpp"



re::Timer::Timer(
    const float& timeInSeconds
) : timeInSeconds(timeInSeconds),
    _isRunning(false) {

    }


void re::Timer::start() {
    this->_isRunning = true;
    this->startedTime = re::globals::currentTime;
}


void re::Timer::update() {
    if (this->_isRunning)
        this->_isRunning = !(re::globals::currentTime - this->startedTime >= this->timeInSeconds);        
}


void re::Timer::reset() {
    this->startedTime = re::globals::currentTime;
    this->start();
}


bool re::Timer::isRunning() const {
    return this->_isRunning;
}