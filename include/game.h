#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
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
        void runEvents();
    protected:
    private:
        Player player;
        sf::RenderWindow App;
};

#endif // GAME_H
