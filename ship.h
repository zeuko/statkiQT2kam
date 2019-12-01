#ifndef SHIP_H
#define SHIP_H
#include "mapa.h"

using namespace std;
class Ship
{
public:
   // Map Mapa;
    Ship(list<Piece*> listOfpiece );
    bool isSunk();
    static bool checkIfCanBeShip(Map *map, int x, int y);
    int randomizePosition();
    static Ship* createThreeMast(Map* Obiekt);
    bool isBlank(Piece* piece);
    bool isShip(Piece* piece);

private:
    list<Piece*> pieces;

};

#endif // SHIP_H
