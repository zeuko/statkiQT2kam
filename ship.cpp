#include "ship.h"
using namespace std;
Ship::Ship(list<Piece*>listOfpiece)
{
    this->pieces = listOfpiece;
};

bool Ship::isSunk()
{
    return true;
};


bool checkIfCanBeShip(Map* map, int x, int y) {
    Piece* piece = map->getPiece(x, y);
    if (piece == NULL) { // NULL - jestesmy poza mapa, nie moze byc tam statku
        return false;
    } else if (piece->getState() != BLANK) { // juz tutaj jest jakis statek
      return false;
    } else { // sprawdzamy sasiadow
      for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
          Piece* checkedPiece = map->getPiece(x+i, x+j);
          if (checkedPiece != NULL && checkedPiece->getState() == BLANK) {
            return false;
          }
        }
      }
    }
    return true;
}


Ship* createThreeMast(Map* Obiekt)
{

    int x,y,tabX,tabY;
    Piece* piece;
    list<Piece*> *listOfPieceShip = new list<Piece*>();

        while(listOfPieceShip->empty())  {
            x = qrand()%10;
            y = qrand()%10;
            tabX = x;
            tabY = y;



        bool canBeShip[5];

                canBeShip[0] = checkIfCanBeShip(Obiekt, tabX-2, tabY);
                canBeShip[1] = checkIfCanBeShip(Obiekt, tabX-1, tabY);
                canBeShip[2] = checkIfCanBeShip(Obiekt, tabX, tabY);
                canBeShip[3] = checkIfCanBeShip(Obiekt, tabX+1, tabY);
                canBeShip[4] = checkIfCanBeShip(Obiekt, tabX+2, tabY);

                int start = -1;
                int numberOfConsecutivePieces = 0;
                for (int i = 0; i < 3; i++) {   // sprawdzamy, czy w tablicy mamy 3 'true' pod rząd (np, [false, true, true, true, false] albo [true, true, true, false, true] albo [true, false, true, true, true] albo cokolwiek innego)
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

                }

                if (numberOfConsecutivePieces == 3) {
                    int positionShift = 2 - start;
                    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift, y));
                    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 1, y));
                    listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 2, y));
                    for(list<Piece*>::iterator it;it != listOfPieceShip->end(); it++)
                    {
                        (*it)->setState(SHIP);
                    }
                }
                    else {
                    // TODO nie da się postawić poziomego statku zawierającego pole (x, y) - szukamy pionowego

                    canBeShip[0] = checkIfCanBeShip(Obiekt, tabX, tabY-2);
                    canBeShip[1] = checkIfCanBeShip(Obiekt, tabX, tabY-1);
                    canBeShip[2] = checkIfCanBeShip(Obiekt, tabX, tabY);
                    canBeShip[3] = checkIfCanBeShip(Obiekt, tabX, tabY+1);
                    canBeShip[4] = checkIfCanBeShip(Obiekt, tabX, tabY+2);

                    for (int i = 0; i < 3; i++)
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

                    }
                    if (numberOfConsecutivePieces == 3) {
                        int positionShift = 2 - start;
                        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift, y));
                        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 1, y));
                        listOfPieceShip->push_back(Obiekt->getPiece(x + positionShift + 2, y));
                        for(list<Piece*>::iterator it;it != listOfPieceShip->end(); it++)
                        {
                            (*it)->setState(SHIP);
                        }
                    }

                    // jezeli pionowego też się nie da, to wtedy klops, i trzeba losować x i y jeszcze raz i szukać nowej pozycji
                }
        }
}

Ship* createTwoMast (Map* Obiekt)
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

        if(numberOfConsecutivePieces == 2){
            int positionShift = 1 - start;
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

