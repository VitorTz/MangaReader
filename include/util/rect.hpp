#ifndef MANGA_READER_RECT_HPP
#define MANGA_READER_RECT_HPP
#include <SFML/System/Vector2.hpp>


namespace og {

    class Rect {

        private:
            sf::Vector2f pos;
            sf::Vector2f size;
        
        public:
            Rect();
            Rect(const sf::Vector2f& pos);
            Rect(
                const sf::Vector2f& pos,
                const sf::Vector2f& size
            );

            void move(const float x, const float y);
            void moveY(const float y);
            void moveX(const float x);

            bool collideRect(const og::Rect& rect) const;

            const sf::Vector2f& getPos() const;
            const sf::Vector2f& getSize() const;
            void setPos(const sf::Vector2f& pos);
            void setSize(const sf::Vector2f& size);

            float left() const;
            float right() const;
            float bottom() const;
            float top() const;

            void setLeft(const float left);
            void setRight(const float right);
            void setBottom(const float bottom);
            void setTop(const float top);

            sf::Vector2f center() const;
            void setCenter(const sf::Vector2f& center);
            float centerX() const;
            float centerY() const;
            void setCenterX(const float centerX);
            void setCenterY(const float centerY);

            float width() const;
            float height() const;

    };
    
} // namespace og



#endif