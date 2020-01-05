#include "bot.h"

Bot::Bot()
{
//list<CoordinatsToShoot*>* neposition = new list<CoordinatsToShoot*>();
    this->position =  new list<CoordinatsToShoot*>();

}


bool Bot :: takeTurn(Map* mapPlayer)
{



    if(this->position->empty() == true) // jesli lista pozycja pusta losujemy z randa
    {
        int x = qrand() % 10;
        int y = qrand() % 10;

        if(mapPlayer->getPiece(x,y)->getState() == State::SHIP) //strzal
        {
            mapPlayer->getPiece(x,y)->setState(HIT);
            if(mapPlayer->getPiece(x,y)->getShip()->isSunk() == true)
            {
                mapPlayer->getPiece(x,y)->getShip()->setIsSunk();
                //mapPlayer->getPiece(x,y)->getShip()->setNeighborsMiss(mapPlayer);

            }
            else
            {
                this->hitX = x;
                this->hitY = y;

                position->push_back(CoordinatsToShoot::oneLeft());
                position->push_back(CoordinatsToShoot::oneRight());
                position->push_back(CoordinatsToShoot::oneDown());
                position->push_back(CoordinatsToShoot::oneUp());
            }
            return true;
        }
        else if(mapPlayer->getPiece(x,y)->getState() != State::SHIP && mapPlayer->getPiece(x,y)->getState() != State::BLANK)
        {
            takeTurn(mapPlayer);
        }
        else {
            mapPlayer->getPiece(x,y)->setState(State::MISS);
            return false;
        }

    }
    else
    {
       int x,y;
       CoordinatsToShoot* cordToShot;
        do {
            cordToShot = position->front();
            position->pop_front();

           x = hitX + cordToShot->getShiftX();
           y = hitY + cordToShot->getShiftY();

        }while(x < 0 || x > 9 || y < 0 || y > 9);

        if(mapPlayer->getPiece(x,y)->getState() == State::SHIP)
        {
            mapPlayer->getPiece(x,y)->setState(State::HIT);
            if(mapPlayer->getPiece(x,y)->getShip()->isSunk() == true)
            {
                mapPlayer->getPiece(x,y)->getShip()->setIsSunk();
            }
            else
            {
                this->hitX = x;
                this->hitY = y;

                if(cordToShot == CoordinatsToShoot::oneLeft())
                {
                    position->clear();
                    position->push_back(CoordinatsToShoot::twoLeft());
                    position->push_back(CoordinatsToShoot::oneRight());
                }
                else if(cordToShot == CoordinatsToShoot::oneRight() )
                {
                    position->clear();
                    position->push_back(CoordinatsToShoot::twoRight());
                    position->push_back(CoordinatsToShoot::oneLeft());
                }
                else if(cordToShot == CoordinatsToShoot::oneDown())
                {
                    position->clear();
                    position->push_back(CoordinatsToShoot::twoDown());
                    position->push_back(CoordinatsToShoot::oneUp());
                }
                else
                {
                    position->clear();
                    position->push_back(CoordinatsToShoot::twoUp());
                    position->push_back(CoordinatsToShoot::oneDown());
                }

            }
            return true;
        }
        else if(mapPlayer->getPiece(x,y)->getState() != State::SHIP && mapPlayer->getPiece(x,y)->getState() != State::BLANK)
        {
            takeTurn(mapPlayer);
        }
        else {
            mapPlayer->getPiece(x,y)->setState(State::MISS);
            return false;
        }



    }
}
