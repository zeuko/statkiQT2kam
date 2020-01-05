#include "CoordinatsToShoot.h"

CoordinatsToShoot :: CoordinatsToShoot  (int x, int y)
{
    this->shiftX = x;
    this->shiftY = y;


}
//lewo
CoordinatsToShoot* CoordinatsToShoot :: oneLeftPoint = new CoordinatsToShoot(-1,0);
CoordinatsToShoot* CoordinatsToShoot :: twoLeftPoint = new CoordinatsToShoot(-2,0);
//prawo
CoordinatsToShoot* CoordinatsToShoot :: oneRightPoint = new CoordinatsToShoot(1,0);
CoordinatsToShoot* CoordinatsToShoot :: twoRightPoint = new CoordinatsToShoot(2,0);
//gora
CoordinatsToShoot* CoordinatsToShoot :: oneUpPoint = new CoordinatsToShoot(0,1);
CoordinatsToShoot* CoordinatsToShoot :: twoUpPoint = new CoordinatsToShoot(0,2);
//dol
CoordinatsToShoot* CoordinatsToShoot :: oneDownPoint = new CoordinatsToShoot(0,-1);
CoordinatsToShoot* CoordinatsToShoot :: twoDownPoint = new CoordinatsToShoot(0,-2);




CoordinatsToShoot* CoordinatsToShoot:: oneLeft()
{
    return oneLeftPoint;
}

CoordinatsToShoot* CoordinatsToShoot :: twoLeft()
{
    return twoLeftPoint;
}

CoordinatsToShoot* CoordinatsToShoot :: oneRight()
{
    CoordinatsToShoot* oneRight = new CoordinatsToShoot(1, 0);

    return oneRight;

}

CoordinatsToShoot* CoordinatsToShoot :: twoRight()
{
    CoordinatsToShoot* twoRight = new CoordinatsToShoot(2, 0);

    return twoRight;

}

CoordinatsToShoot* CoordinatsToShoot :: oneDown()
{
    CoordinatsToShoot* oneDown = new CoordinatsToShoot(0, -1);

    return oneDown;

}

CoordinatsToShoot* CoordinatsToShoot :: twoDown()
{
    CoordinatsToShoot* twoDown = new CoordinatsToShoot(0, -2);

    return twoDown;

}

CoordinatsToShoot* CoordinatsToShoot :: oneUp()
{
    CoordinatsToShoot* oneUp = new CoordinatsToShoot(0,1);

    return oneUp;

}

CoordinatsToShoot* CoordinatsToShoot :: twoUp()
{
    CoordinatsToShoot* twoUp = new CoordinatsToShoot(0, 2);

    return twoUp;

}
int CoordinatsToShoot :: getShiftX()
{
    return shiftX;
}


int CoordinatsToShoot :: getShiftY()
{
    return shiftY;
}
