#include "../include/invader.h"

Invader::Invader(double x, double y)
{
    rectangle.setSize(sf::Vector2f(20, 10));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOrigin(rectangle.getSize().x/2.0,rectangle.getSize().y/2.0);
    rectangle.setPosition(x, y);
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
    rectangle.setPosition(this->x,this->y);
    //If our bullet is in the air..
    if(bullet.getState())
    {
        //Run the logic!
        bullet.bulletLogic();
    }
    else
    {
        //Otherwise keep its position up to date!
        bullet.resetBull(rectangle.getPosition());
    }
}

void Invader::translate(double x, double y)
{
    this->x+=x;
    this->y+=y;
    rectangle.setPosition(this->x,this->y);
    if(!bullet.getState())
    {
        bullet.resetBull(rectangle.getPosition());
    }
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

sf::RectangleShape Invader::getRect() const
{
    return rectangle;
}

Bullet * Invader::getBull()
{
    Bullet *pBull = &bullet;
    return (pBull);
}

void Invader::setVelocity(Vector velocity)
{
    this->velocity=velocity;
}

Invader::~Invader()
{
    //dtor
}
