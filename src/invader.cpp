#include "../include/invader.h"

Invader::Invader(double x, double y)
{
    this->x = x;
    this->y = y;

    //Initally, they all go to the right
    velocity = Vector(1.0,0);

    //ctor
}

void Invader::update()
{
    x += velocity.getXComponent();
    y += velocity.getYComponent();
}

void Invader::translate(double x, double y)
{
    this->x+=x;
    this->y+=y;
}

double Invader::getX() const
{
    return x;
}

double Invader::getY() const
{
    return y;
}

Vector Invader::getVelocity() const
{
    return velocity;
}

Vector Invader::setVelocity(Vector velocity)
{
    this->velocity=velocity;
}

Invader::~Invader()
{
    //dtor
}
