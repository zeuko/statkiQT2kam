#ifndef BOT_H
#define BOT_H
#include "mapa.h"

class Bot
{
public:
    Bot();
    bool chceckIsHit(Map* map,int x,int y) ;
    void brainBot(Map *map);

private:
    int tempX;
    int tempY;
    bool lastShoot;
    int counterSunk;
    bool shipSunk;
    bool shootDir[4];
    int direction = 0;
};

#endif // BOT_H
