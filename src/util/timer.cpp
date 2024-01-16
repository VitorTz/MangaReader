#include "../../include/util/timer.hpp"



re::Timer::Timer(
    const float timeInSeconds
) : timeInSeconds(timeInSeconds),
    m_is_running(false) {

    }


void re::Timer::reset() {
    this->m_is_running = true;
    this->startedTime = this->clock.getElapsedTime().asSeconds();
}


bool re::Timer::isRunning() {
    if (this->m_is_running) {
        this->m_is_running = !(
            this->clock.getElapsedTime().asSeconds() - this->startedTime >= this->timeInSeconds
        );        
    }
    return this->m_is_running;
}