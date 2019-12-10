#ifndef BOT_H
#define BOT_H
#include "mapa.h"

class Bot
{
public:
    Bot();
    void takeTurn(Map *map);

    static bool shoot(Map *map, int x, int y);
    static bool isBlank(Map *map, int x, int y);

    void setHit(bool hitted);
    bool getHit();
private:
    bool hit;

};

#endif // BOT_H
