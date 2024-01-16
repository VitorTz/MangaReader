#include "../../include/util/notification_manager.hpp"

std::unique_ptr<re::Notification> re::NotificationManager::notification;


re::Timer re::NotificationManager::timer(4);


void re::NotificationManager::showNotification(const std::string& txt) {
    re::NotificationManager::timer.reset();    
    re::NotificationManager::notification = std::make_unique<re::Notification>(txt);
}


void re::NotificationManager::update(const float& dt) {
    if (re::NotificationManager::timer.isRunning()) {        
        re::NotificationManager::notification->update(dt);
    }
}

void re::NotificationManager::draw(sf::RenderWindow& window) {
    if (re::NotificationManager::timer.isRunning()) {
        re::NotificationManager::notification->draw(window);
    }
}