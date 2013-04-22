#include "../include/invader.h"

Invader::Invader(double x, double y)
{
    rectangle.setSize(sf::Vector2f(20, 10));
    rectangle.setFillColor(sf::Color::White);
    //rectangle.setOutlineThickness(5);
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
}

void Invader::translate(double x, double y)
{
    this->x+=x;
    this->y+=y;
    rectangle.setPosition(this->x,this->y);
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

Vector Invader::setVelocity(Vector velocity)
{
    this->velocity=velocity;
}

Invader::~Invader()
{
    //dtor
}
