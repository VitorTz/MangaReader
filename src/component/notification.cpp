#include "../../include/component/notification.hpp"


re::Notification::Notification(
    const std::string& txt
) : re::Component("Notification", {}),
    border({}, 2, re::Colors::PINK_200),
    background({}, re::Colors::GREY_200),
    text(txt, {}, re::style::notificationTxtStyle, 500) {
    this->transform.setWidth(this->text.transform.width() + 50);
    this->transform.setHeight(this->text.transform.height() + 30);
    this->transform.setLeft(re::SCREEN_WIDTH + 20);
    this->transform.setTop(20);
    this->border.transform.size = this->transform.size;
    this->background.transform.pos = this->transform.pos;
    this->background.transform.size = this->transform.size;
    this->border.transform.pos = this->transform.pos;
    this->text.transform.setCenter(this->transform.center());
}


void re::Notification::update(const float& dt) {
    const float right = re::SCREEN_WIDTH - 20;
    if (this->transform.right() > right)
        this->transform.moveX(-dt * 1250);
}


void re::Notification::draw(sf::RenderWindow& window) {
    this->background.transform.pos = this->transform.pos;
    this->border.transform.pos = this->transform.pos;
    this->text.transform.setCenter(this->transform.center());
    this->background.draw(window);
    this->border.draw(window);
    this->text.draw(window);
}