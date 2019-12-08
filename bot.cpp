#include "bot.h"
#include "ship.h"
Bot::Bot()
{

}
/*
bool Bot :: chceckIsHit(Map* map,int x,int y) //sprawdza czy na danym polu jest statek
{
    if(map->getPiece(x,y)->getState() == SHIP)
    {
        return true;
    }
}



void  Bot :: brainBot(Map* map)
{
    int x;
    int y;


    if(lastShoot == false)
    {
        x = qrand()%10;
        y = qrand()%10;

        if (Bot::chceckIsHit(map,x,y) == true && shipSunk == false)
        {
            map->getPiece(x,y)->setState(HIT);
            tempX = x;
            tempY = y;
            lastShoot = true; // oznacza ze trafilismy statek


        }
        else if(lastShoot == true)// jesli trafiony to lece wokol niego szukjac w ktora strone jest // wiem brakuje sprawdzania dalszych pol ale wydaje mi sie zle bo nie obsluguje tu obiektu statku wiec tak wstepnie napisalem
        {

                    if (Bot::chceckIsHit(map,tempX-1,tempY) == true && shipSunk == false && shootDir[0] == false)
                        {
                            map->getPiece(tempX,tempX)->setState(HIT); //zmiana statusu pieca
                            shootDir[0] = true; // kierunek strzalu 0,1 to jest x 2,3 to y
                            direction++;  //licznik tablicy
                        }

                    else if (Bot::chceckIsHit(map,tempX+1,tempY) == true && shipSunk == false && shootDir[1] == false)
                        {
                            map->getPiece(tempX,tempX)->setState(HIT);

                            shootDir[1] = true;
                            direction++;
                        }
                    else
                    {
                        direction++;
                        if (Bot::chceckIsHit(map,tempX,tempY+1) == true && shipSunk == false && shootDir[2] == false)
                            {
                                map->getPiece(tempX,tempX)->setState(HIT);

                                shootDir[2] = true;
                                direction++;
                            }
                        else if (Bot::chceckIsHit(map,tempX,tempY-1) == true && shipSunk == false && shootDir[3] == false)
                            {
                                map->getPiece(tempX,tempX)->setState(HIT);

                                shootDir[3] = true;
                                direction++;
                            }
                        else{ // ten else jak juz zatopimy
                            direction = 0; // zerujemy licznik dir
                            lastShoot = false; //zmieniamy ze juz nie ma statku trafionego
                            shipSunk = true; // zatopiony statek
                            memset(shootDir,false,4); // zerowanie tablicy z kierunkami
                        }
                    }


        }




        else{
            if(map->getPiece(x,y)->getState() == BLANK) // jesli pole strzelone to "BLANK" to zmien na MISS
            {

                map->getPiece(x,y)->setState(MISS);
            }

        }
    }



}
*/
