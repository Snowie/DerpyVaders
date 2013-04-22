#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "vector.h"
#include "bullet.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        void control();
        void update();
        sf::RectangleShape getRect() const;
        Bullet * getBull();

    protected:
    private:

        Bullet bullet;

        sf::RectangleShape rectangle;
        Vector velocity;
        Vector acceleration;

        double x, y;
};

#endif // PLAYER_H
