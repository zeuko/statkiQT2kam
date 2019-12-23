#ifndef BOT_H
#define BOT_H
#include "mapa.h"
#include "ship.h"
#include "piecetoshoot.h"
class Bot
{
public:
    Bot();
    bool takeTurn(Map* mapPlayer);

private:
    list<PieceToShoot*>* position;

    int hitX = -1;
    int hitY = -1;



};

#endif // BOT_H
