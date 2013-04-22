#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "vector.h"

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();
        sf::RectangleShape getRect() const;
        void resetBull(sf::Vector2f);
        bool getState() const;
        void activate();
        bool bulletLogic();
    protected:
    private:
        sf::RectangleShape rectangle;
        bool bulletState;
        double bull_x, bull_y;
        Vector bulletVelocity;
};

#endif // BULLET_H
