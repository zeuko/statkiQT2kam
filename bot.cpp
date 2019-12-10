#include "bot.h"
#include "ship.h"
Bot::Bot()
{

}



bool Bot:: shoot(Map *map, int x, int y)
{
    if(map->getPiece(x,y)->getState() == SHIP)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool Bot:: isBlank(Map *map, int x, int y)
{
    if(map->getPiece(x,y)->getState() == BLANK)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Bot:: setHit(bool hitted)
{
      this->hit = hitted;

}


bool Bot:: getHit()
{
    return  hit;
}


void  Bot :: takeTurn(Map* map)
{

    int x;
    int y;

    if(hit == false)
    {
        while(isBlank(map,x,y) == false)
        {
            x = qrand()%10;
            y = qrand()%10;
        }


    }




}

