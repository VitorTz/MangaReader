#ifndef AFC2875F_B445_4613_BA10_881B2818DC52
#define AFC2875F_B445_4613_BA10_881B2818DC52
#include "../component/notification.hpp"
#include "timer.hpp"


namespace re {


    class NotificationManager {

        private:

            static std::unique_ptr<re::Notification> notification;
            static re::Timer timer;

        public:
            static void showNotification(const std::string& txt);
            static void update(const float& dt);
            static void draw(sf::RenderWindow& window);

    };
    
} // namespace re


#endif /* AFC2875F_B445_4613_BA10_881B2818DC52 */
