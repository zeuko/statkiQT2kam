#ifndef SHIP_H
#define SHIP_H

#include "mapa.h"

using namespace std;
class Piece;
class Map;
class Ship
{
public:

    Ship(list<Piece*> listOfpiece );
    bool isSunk(Ship);
    static bool checkIfCanBeShip(Map *map, int x, int y);
    int randomizePosition();

    static Ship* createTwoMast(Map* Obiekt);
    static Ship* createOneMast(Map* Obiekt);
    bool isBlank(Piece* piece);
    bool isShip(Piece* piece);

    Piece *createThreeMastVertical();

   static Ship* createThreeMast(Map* Obiekt);
   static list<Piece*>* createThreeMastVertical(Map* Obiekt, int x, int y) ;
   static list<Piece*>* createThreeMastHorizontal(Map *Obiekt, int x, int y);
private:
    list<Piece*> pieces;

};

#endif // SHIP_H
