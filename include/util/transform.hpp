#pragma once
#include <SFML/System/Vector2.hpp>


namespace re {

    class Transform {

        private:
            sf::Vector2f pos;
            sf::Vector2f size;

        public:
            Transform();
            Transform(const sf::Vector2f& pos);
            Transform(
                const sf::Vector2f& pos,
                const sf::Vector2f& size
            );

            const sf::Vector2f& getPos() const;
            void setPos(const sf::Vector2f& pos);
            const sf::Vector2f& getSize() const;
            void setSize(const sf::Vector2f& size);

            float left() const;
            float right() const;
            float bottom() const;
            float top() const;

            void setLeft(const float left);
            void setRight(const float right);
            void setBottom(const float bottom);
            void setTop(const float top);

            float width() const;
            float height() const;
            void setWidth(const float width);
            void setHeight(const float height);

            sf::Vector2f center() const;
            void setCenter(const sf::Vector2f& center);

            float centerX() const;
            float centerY() const;
            void setCenterX(const float x);
            void setCenterY(const float y);

            void moveY(const float y);
            void moveX(const float x);
            void move(const sf::Vector2f& v);

            bool collide(const re::Transform& t);

            bool collidePoint(const sf::Vector2f& pos);

    };
    
} // namespace re

