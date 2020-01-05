#ifndef PIECETOSHOOT_H
#define PIECETOSHOOT_H
class CoordinatsToShoot;
class CoordinatsToShoot
{
public:
    static CoordinatsToShoot* oneLeft();
    static CoordinatsToShoot* twoLeft();
    static CoordinatsToShoot* oneRight();
    static CoordinatsToShoot* twoRight();
    static CoordinatsToShoot* oneUp();
    static CoordinatsToShoot* twoUp();
    static CoordinatsToShoot* oneDown();
    static CoordinatsToShoot* twoDown();
    int getShiftX();
    int getShiftY();
    //static CoordinatsToShoot* twoLeft = new CoordinatsToShoot(-2, 0);

private:

    CoordinatsToShoot(int x, int y);

    int shiftX;
    int shiftY;
    ~CoordinatsToShoot();
     static CoordinatsToShoot* oneLeftPoint;
     static CoordinatsToShoot* twoLeftPoint;

     static CoordinatsToShoot* oneRightPoint;
     static CoordinatsToShoot* twoRightPoint;

     static CoordinatsToShoot* oneUpPoint;
     static CoordinatsToShoot* twoUpPoint;

     static CoordinatsToShoot* oneDownPoint;
     static CoordinatsToShoot* twoDownPoint;


};

#endif // PIECETOSHOOT_H
