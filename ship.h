#ifndef SHIP_H
#define SHIP_H

#include "mapa.h"

using namespace std;
class Piece;
class Map;
class Ship
{
public:

    Ship(list<Piece *> *listOfpiece );
    bool isSunk();
    static bool checkIfCanBeShip(Map *map, int x, int y);
    int randomizePosition();

    static Ship* createTwoMast(Map* Obiekt);
    static Ship* createOneMast(Map* Obiekt);
    bool isBlank(Piece* piece);



   static list<Piece *> *createTwoMastVertical(Map *Obiekt, int x, int y);
    static Ship* createThreeMast(Map* Obiekt);
    static list<Piece*>* createThreeMastVertical(Map* Obiekt, int x, int y) ;
    static list<Piece*>* createThreeMastHorizontal(Map *Obiekt, int x, int y);

    static list<Piece *> *createTwoMastHorizontal(Map *Obiekt, int x, int y);

    list<Piece *>* getListShip();
private:
    list<Piece*>* pieces;


};

#endif // SHIP_H
