#include "../include/player.h"
#include <iostream>

Player::Player()
{
    //PLACEHOLDER, PLEASE REPLACE
    x = 0;
    y = 0;
    //ctor
}

void Player::control()
{
    acceleration = Vector();
    //Go left!
    //Creates an acceleration vector pointing to the left (Theta = 180)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        acceleration = Vector(1, 180);
    }

    //Go right!
    //Creates an acceleration vector pointing to the Right (Theta = 0)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        acceleration = Vector(1, 0);
    }

    //Space to shoot
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //fire!
    }
}

void Player::update()
{
    long double velocity_x = velocity    .getXComponent();
    long double velocity_y = velocity    .getYComponent();

    long double accel_x    = acceleration.getXComponent();
    long double accel_y    = acceleration.getYComponent();

    velocity_x            += accel_x;
    velocity_y            += accel_y;

    long double newMag     = sqrt(pow(velocity_x,2) + pow(velocity_y,2));
    long double newTheta   = atan2(velocity_y,velocity_x)*(180.0l/PI);

    velocity               = Vector(newMag,newTheta);

    x                     += velocity_x;
    y                     += velocity_y;

    std::cout << "Position (x,y): (" << x << "," << y << ")" << std::endl;
}

Player::~Player()
{
    //dtor
}
