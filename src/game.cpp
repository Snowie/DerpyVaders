#include "../include/game.h"

Game::Game()
{
    //ctor
    App.create(sf::VideoMode(1920,1030), "DerpyVaders");
    App.setVerticalSyncEnabled(true);
}

void Game::initInvaders()
{
    //Rows
    for(unsigned int j = 0; j < 5; ++j)
    {
        //Columns
        for(unsigned int k = 0; k < 11; ++k)
        {
            //Constants are placeholders, will replace with variables representing height and width
            invaders.push_back(Invader(k*5,j*5));
        }
    }
}

void Game::init()
{
    initInvaders();
    loop();
}

void Game::invaderLogic()
{
    bool update = false;


    //Boundary checking
    for(Invader x: invaders)
    {
        //If one is touching the border
        {
            //update = true;
            //break;
        }
    }

    if(update)
    {
        //Translation and velocity switching
        for(Invader & x: invaders)
        {
            x.translate(0,1);
            x.setVelocity(Vector(x.getVelocity().getMagnitude(), x.getVelocity().getTheta()+180));
        }
    }

    //Finally move.
    for(Invader & x: invaders)
    {
        x.update();
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
}

void Game::loop()
{
    while(App.isOpen())
    {
        //Generic application stuff
        runEvents();

        //Allow the player to query the state of controls
        player.control();

        //Update the player based on its current state
        player.update();

        //That cool formation logic you see
        invaderLogic();

        App.clear();
        //App.draw();
        App.display();
    }
}

Game::~Game()
{
    //dtor
}
