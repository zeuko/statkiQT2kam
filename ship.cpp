#include "ship.h"
#include <QTime>
#include <QRandomGenerator>
using namespace std;
Ship::Ship(list<Piece*>listOfpiece)
{
    for(list<Piece*>::iterator it = listOfpiece.begin();it != listOfpiece.end(); it++)
    {
        (*it)->setPointerShip(this);
    }
};

bool Ship::isSunk(Ship)
{
    int numberOfHit = 0;//licznik trafionych

    int sizeShip = pieces.size();


    for(list<Piece*>::iterator it = pieces.begin() ; it != pieces.end(); ++it)
    {
        if((*it)->getState() == HIT)
            numberOfHit++;

        if(numberOfHit == sizeShip)
        {
            return true;
        }

    }
    return false;
};


bool Ship :: checkIfCanBeShip(Map* map, int x, int y) {
    Piece* piece = map->getPiece(x, y);
    //  cout <<"["<< x << " " << y <<"] ";
    if (piece == NULL) { // NULL - jestesmy poza mapa, nie moze byc tam statku
        return false;
    } else if (piece->getState() != BLANK) { // juz tutaj jest jakis statek
        return false;
    } else { // sprawdzamy sasiadow
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                Piece* checkedPiece = map->getPiece(x+i, y+j);
                if (checkedPiece != NULL && checkedPiece->getState() != BLANK) {
                    return false;
                }
            }
        }
    }

    return true;
}

list<Piece*>* Ship::createThreeMastVertical(Map* Obiekt, int x, int y)
{

    bool canBeShip[5];
    int tabX = x;
    int tabY = y;
    int start = -1;
    int numberOfConsecutivePieces = 0;



    canBeShip[0] = checkIfCanBeShip(Obiekt, tabX, tabY-2);
    canBeShip[1] = checkIfCanBeShip(Obiekt, tabX, tabY-1);
    canBeShip[2] = checkIfCanBeShip(Obiekt, tabX, tabY);
    canBeShip[3] = checkIfCanBeShip(Obiekt, tabX, tabY+1);
    canBeShip[4] = checkIfCanBeShip(Obiekt, tabX, tabY+2);

    for (int i = 0; i < 5; i++)
    {

        if(canBeShip[i] == true)
        {
            if(start == -1)
            {
                start = i;
                numberOfConsecutivePieces = 1;
            }
            else
            {
                numberOfConsecutivePieces++;
            }
        }
        else
        {
            start = -1;
            numberOfConsecutivePieces = 0;
        }
        if (numberOfConsecutivePieces == 3) {

            break;
        }

    }

    if (numberOfConsecutivePieces == 3) {
        list<Piece*>*listOfPieceShip = new list<Piece*>();
        int positionShift =  start -2;
        listOfPieceShip->push_back(Obiekt->getPiece(x , y + positionShift));
        listOfPieceShip->push_back(Obiekt->getPiece(x , y + positionShift + 1));
        listOfPieceShip->push_back(Obiekt->getPiece(x , y + positionShift + 2));
        for(list<Piece*>::iterator it = listOfPieceShip->begin();it != listOfPieceShip->end(); it++)
        {
            (*it)->setState(SHIP);

        }
        return listOfPieceShip;
    }
    else {
        return  nullptr;
    }

}


list<Piece*>* Ship::createThreeMastHorizontal (Map* Obiekt, int x, int y)
{



    int tabX = x;
    int tabY = y;



    bool canBeShip[5];

    canBeShip[0] = checkIfCanBeShip(Obiekt, tabX-2, tabY);
    canBeShip[1] = checkIfCanBeShip(Obiekt, tabX-1, tabY);
    canBeShip[2] = checkIfCanBeShip(Obiekt, tabX, tabY);
    canBeShip[3] = checkIfCanBeShip(Obiekt, tabX+1, tabY);
    canBeShip[4] = checkIfCanBeShip(Obiekt, tabX+2, tabY);

    int start = -1;
    int numberOfConsecutivePieces = 0;
    for (int i = 0; i < 5; i++) {   // sprawdzamy, czy w tablicy mamy 3 'true' pod rząd (np, [false, true, true, true, false] albo [true, true, true, false, true] albo [true, false, true, true, true] albo cokolwiek innego)
        // iterujemy tylko dla wartosci 0, 1, 2 bo tylko te indeksy mogą być początkiem naszego statku (czyli sprawdzamy statki zaczynajace sie od lewej strony)

        if (canBeShip[i] == true) {   // na pozycji i jest puste pole - wiec albo zaczyna sie w tym miejscu statek, albo jest to kolejne pole statku
            if (start == -1) {
                start = i;

                numberOfConsecutivePieces = 1;
            } else {

                numberOfConsecutivePieces++;
            }
        } else {   // na pozycji i mamy zajete pole, więc cokolwiek do tej pory znaleźliśmy nie ma już znaczenia - resetujemy się
            start = -1;
            numberOfConsecutivePieces = 0;

        }
        if (numberOfConsecutivePieces == 3) {

            break;
        }

    }

    if (numberOfConsecutivePieces == 3) {
        list<Piece*>*listOfPieceShip = new list<Piece*>();
        int positionShift = start-2;
        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift, y));
        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 1, y));
        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 2, y));
        for(list<Piece*>::iterator it = listOfPieceShip->begin();it != listOfPieceShip->end(); it++)
        {
            (*it)->setState(SHIP);

        }
        return listOfPieceShip;
    }
    else{
        return nullptr;
    }
}









Ship* Ship :: createThreeMast(Map* Obiekt)
{
    int  x =  qrand() % 10;
    int  y = qrand() % 10;
    int randPosition = qrand()%10;
    cout <<"["<< x << " "<<randPosition%2<<" " << y <<"] ";
    bool makeShip = false;
    list<Piece*>* lista;


    if(randPosition%2 == 0)
    {
        while (makeShip == false ) {
            lista = createThreeMastVertical(Obiekt,x,y);
            if(lista != NULL){
                makeShip = true;
                Ship* ship = new Ship(*lista);
                return ship;
            }
            else {
                lista =createThreeMastHorizontal(Obiekt,x,y);
                if(lista != NULL){
                    makeShip = true;
                    Ship* ship = new Ship(*lista);
                    return ship;
                }
                else {
                    x =  qrand() % 10;
                    y = qrand() % 10;
                }
            }
        }
    }
    else {
        while (makeShip == false) {
            lista =createThreeMastHorizontal(Obiekt,x,y);
            if(lista != NULL){
                makeShip = true;
                Ship* ship = new Ship(*lista);
                return ship;
            }
            else {
                lista = createThreeMastVertical(Obiekt,x,y);

                if(lista != NULL){
                    makeShip = true;
                    Ship* ship = new Ship(*lista);
                    return ship;
                }
                else {
                    x =  qrand() % 10;
                    y = qrand() % 10;
                }
            }
        }
    }


    /*
    list<Piece*>* lista = createThreeMastVertical(Obiekt,x,y);
    Ship* ship = new Ship(*lista);
            return ship;
*/
}
/*
 Ship*  Ship:: createTwoMast (Map* Obiekt)
{
    int x,y,tabX,tabY;
    Piece* piece;
    list<Piece*> *listOfPieceShip = new list<Piece*>();

    bool canBeShip[3];
   while(listOfPieceShip->empty())
       {
        x = qrand()%10;
        y = qrand()%10;
        tabX = x;
        tabY = y;


        canBeShip[0] = checkIfCanBeShip(Obiekt, tabX + 1, tabY);
        canBeShip[1] = checkIfCanBeShip(Obiekt, tabX, tabY);
        canBeShip[2] = checkIfCanBeShip(Obiekt, tabX - 1, tabY);




        int start = -1;
        int numberOfConsecutivePieces = 0;

        for(int i = 0; i < 2; i++)
        {
            if(canBeShip[i] == true){
                if(start == -1){
                    start = i;
                    numberOfConsecutivePieces = 1;
                }
                    else{
                        numberOfConsecutivePieces++;
                }
            } else {
                start = -1;
                numberOfConsecutivePieces = 0;
            }

        }
                                                                                                        ąążżzzz  s       ąążżzzz
        if(numberOfConsecutivePieces == 2){                                                             ąążżzzz  s       ąążżzzz
            int positionShift = 1 - start;                                                        ą     ąążżzzz  s ą     ąążżzzz
            listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift,y));
    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 1,y));

            for(list<Piece*>::iterator it;it != listOfPieceShip->end(); it++)
            {
                (*it)->setState(SHIP);
            }
        }
            else{

                canBeShip[0] = checkIfCanBeShip(Obiekt, tabX, tabY-1);
                canBeShip[1] = checkIfCanBeShip(Obiekt, tabX, tabY);
                canBeShip[2] = checkIfCanBeShip(Obiekt, tabX, tabY+1);

                for(int i = 0; i < 2; i++)
                {
                    if(canBeShip[i] == true){
                        if(start == -1){
                            start = i;
                            numberOfConsecutivePieces = 1;
                        }
                            else{
                                numberOfConsecutivePieces++;
                        }
                    } else {
                        start = -1;
                        numberOfConsecutivePieces = 0;
                    }

                }
                if(numberOfConsecutivePieces == 2)
                {
                    int positionShift = 1 - start;
                    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift,y));
                    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 1,y));

                    for(list<Piece*>::iterator it;it != listOfPieceShip->end(); it++)
                    {
                        (*it)->setState(SHIP);
                    }
                }


            }



    }
}


Ship* Ship:: createOneMast (Map* Obiekt){

    int x,y,tabX,tabY;
    Piece* piece;
    list<Piece*> *listOfPieceShip = new list<Piece*>();
    Piece* oneShip;
    while(listOfPieceShip->empty()){
        x = qrand()%10;
        y = qrand()%10;
        tabX = x;
        tabY = y;

        if(checkIfCanBeShip(Obiekt,x,y)){
            oneShip = Obiekt->getPiece(x,y);
            oneShip->setState(SHIP);
            listOfPieceShip->push_back(oneShip);
        }

     }

}
*/
