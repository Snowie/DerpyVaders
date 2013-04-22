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
        void loop();
        bool checkColl(sf::RectangleShape, sf::RectangleShape) const;
    protected:
    private:
        void initInvaders();
        void invaderLogic();
        void runEvents();
        Player player;
        sf::RenderWindow App;
        std::vector<Invader> invaders;
};

#endif // GAME_H
