#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "vector.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        void control();
        void update();
        sf::RectangleShape getRect() const;
        sf::RectangleShape getBull() const;
        void eraseBull();

        bool getBullState() const;
    protected:
    private:

        void bulletLogic();

        sf::RectangleShape rectangle;
        sf::RectangleShape bullet;
        Vector velocity;
        Vector acceleration;

        bool bulletState;
        double bull_x, bull_y;
        double x, y;
        Vector bulletVelocity;
};

#endif // PLAYER_H
