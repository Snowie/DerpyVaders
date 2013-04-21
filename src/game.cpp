#include "../include/game.h"

Game::Game()
{
    //ctor
    App.create(sf::VideoMode(1920,1030), "DerpyVaders");
    App.setVerticalSyncEnabled(true);
}

void Game::init()
{
    loop();
}

void Game::invaderLogic()
{
    bool update = false;


    //Boundary checking
    for(Invader x: invaders)
    {
        //If one is touching the border
            //update = true;
            //break;
    }

    if(update)
    {
        //Translation and velocity switching
        for(Invader & x: invaders)
        {
            //x.translate(0,x.height);
            //x.velocity = Vector(x.velocity.getMagnitude(), x.velocity.getTheta()+180);
        }
    }

    //Finally move.
    for(Invader & x: invaders)
    {
        //x.update();
    }
}

void Game::runEvents()
{
    sf::Event event;
    while(App.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            App.close();
            break;
        }
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                App.close();
                break;
            }
        }
    }

    player.control();
    player.update();

    invaderLogic();
}

void Game::loop()
{
    while(App.isOpen())
    {
        runEvents();
        App.clear();
        //App.draw();
        App.display();
    }
}

Game::~Game()
{
    //dtor
}
