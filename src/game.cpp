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
