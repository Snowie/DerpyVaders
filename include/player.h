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
    protected:
    private:
        double x, y;
        Vector velocity;
        Vector acceleration;
};

#endif // PLAYER_H
