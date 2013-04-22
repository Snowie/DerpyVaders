#include "../include/game.h"
#include <time.h>
#include <cstdlib>
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

    srand(time(0));
    //Boundary checking
    for(Invader & inv: invaders)
    {
        //If we are touching the sides...
        if(inv.getRect().getPosition().x + inv.getVelocity().getXComponent() > App.getSize().x || inv.getRect().getPosition().x + inv.getVelocity().getXComponent()< 0)
        {
            //Set the update flag and break
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
    for(Invader & inv: invaders)
    {
        //Random check to see if an invader should fire
        int someNum = rand() % 1000 + 1;
        if(someNum > 990 && !inv.getBull()->getState())
        {
            inv.getBull()->activate();
            inv.getBull()->setVelocity(Vector(8.0,90.0));
        }

        //Continue moving
        inv.update();
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


//Ugly collision detection!
bool Game::checkColl(sf::RectangleShape first, sf::RectangleShape second) const
{
    double firstMaxX = first.getPosition().x + first.getSize().x/2.0;
    double firstMinX = first.getPosition().x - first.getSize().x/2.0;
    double firstMaxY = first.getPosition().y + first.getSize().y/2.0;
    double firstMinY = first.getPosition().y - first.getSize().y/2.0;

    double secondMaxX = second.getPosition().x + second.getSize().x/2.0;
    double secondMinX = second.getPosition().x - second.getSize().x/2.0;
    double secondMaxY = second.getPosition().y + second.getSize().y/2.0;
    double secondMinY = second.getPosition().y - second.getSize().y/2.0;

    if (firstMaxX < secondMinX ||
        firstMaxY < secondMinY ||
        firstMinX > secondMaxX ||
        firstMinY > secondMaxY)
    {
        return false;
    }
    else
    {
        return true;
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

        //Draw the invaders
        for(Invader inv: invaders)
        {
            App.draw(inv.getRect());
        }

        //An integer to keep track of our offset
        unsigned int i = 0;

        //Should we delete the invader at that offest?
        bool del = false;

        //If the player's bullet is in the air
        if(player.getBull()->getState())
        {
            for(Invader inv: invaders)
            {
                //If it isn't colliding
                if(!checkColl(inv.getRect(),player.getBull()->getRect()))
                {
                    //Continue checking
                    ++i;
                    continue;
                }
                else
                {
                    //Set the delete flag and break, we've hit one!
                    del = true;
                    break;
                }
            }
        }

        //Flag to keep track of whether the player has been hit
        bool playerHit = false;

        for(Invader & inv: invaders)
        {
            //If the invader has a bullet in the air...
            if(inv.getBull()->getState())
            {
                //Check for a collision
                if(checkColl(player.getRect(), inv.getBull()->getRect()))
                {
                    //Close as game over if there was one
                    playerHit = true;
                    App.close();
                    break;
                }
            }
        }

        //Delete the invader at offset i
        if(del)
        {
            invaders.erase(invaders.begin()+i);
            player.getBull()->resetBull(player.getRect().getPosition());
        }

        //Draw all active invader bullets
        for(Invader inv: invaders)
        {
            if(inv.getBull()->getState())
            {
                App.draw(inv.getBull()->getRect());
            }
        }

        //Draw the player bullet if active
        if(player.getBull()->getState())
        {
            App.draw(player.getBull()->getRect());
        }

        //draw the player
        App.draw(player.getRect());

        App.display();
    }
}

Game::~Game()
{
    //dtor
}
