#ifndef INVADER_H
#define INVADER_H
#include <SFML/Graphics.hpp>
#include "vector.h"
#include "bullet.h"

class Invader
{
    public:
        Invader(double, double);
        virtual ~Invader();
        void update();
        void translate (double, double);
        double getX() const;
        double getY() const;
        Vector getVelocity() const;
        sf::RectangleShape getRect() const;
        void setVelocity(Vector);
        Bullet * getBull();

    protected:
    private:
        Bullet bullet;
        sf::RectangleShape rectangle;
        double x, y;
        Vector velocity;
};

#endif // INVADER_H
