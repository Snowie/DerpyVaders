#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "vector.h"
#include "player.h"
#include "invader.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void init();
        void initInvaders();
        void loop();
        void runEvents();
    protected:
    private:
        void invaderLogic();
        Player player;
        sf::RenderWindow App;
        std::vector<Invader> invaders;
};

#endif // GAME_H
