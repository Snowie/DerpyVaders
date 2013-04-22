#include "../include/game.h"
#include <iostream>
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
            invaders.push_back(Invader(k*5*30,j*5*10));
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
    for(Invader inv: invaders)
    {
        if(inv.getRect().getPosition().x + inv.getVelocity().getXComponent() > App.getSize().x || inv.getRect().getPosition().x + inv.getVelocity().getXComponent()< 0)
        {
            update = true;
            break;
        }
    }

    if(update)
    {
        //Translation and velocity switching
        for(Invader & x: invaders)
        {
            x.translate(0,50);
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

        for(Invader x: invaders)
        {
            App.draw(x.getRect());
        }
        unsigned int i = 0;
        bool del = false;
        if(player.getBullState())
        {
            for(Invader inv: invaders)
            {
                double invMaxX = inv.getRect().getPosition().x + inv.getRect().getSize().x/2.0;
                double invMinX = inv.getRect().getPosition().x - inv.getRect().getSize().x/2.0;
                double invMaxY = inv.getRect().getPosition().y + inv.getRect().getSize().y/2.0;
                double invMinY = inv.getRect().getPosition().y - inv.getRect().getSize().y/2.0;

                double maxX = player.getBull().getPosition().x + player.getBull().getSize().x/2.0;
                double minX = player.getBull().getPosition().x - player.getBull().getSize().x/2.0;
                double maxY = player.getBull().getPosition().y + player.getBull().getSize().y/2.0;
                double minY = player.getBull().getPosition().y - player.getBull().getSize().y/2.0;

                if ((maxX < invMinX ||
                    maxY < invMinY ||
                    minX > invMaxX ||
                    minY > invMaxY))
                    {
                        ++i;
                        continue;
                    }
                    else
                    {
                        del = true;
                        break;
                    }
            }
        }
        if(del)
        {
            invaders.erase(invaders.begin()+i);
            player.eraseBull();
        }

        if(player.getBullState())
        {
            App.draw(player.getBull());
        }
        App.draw(player.getRect());

        App.display();
    }
}

Game::~Game()
{
    //dtor
}
