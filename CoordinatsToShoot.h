#ifndef PIECETOSHOOT_H
#define PIECETOSHOOT_H
class CoordinatsToShoot; // XX usun ta linijke
class CoordinatsToShoot
{
public:


    int getShiftX();  // XX formatowanie
    int getShiftY();
 CoordinatsToShoot(int x, int y);

private:

   // CoordinatsToShoot(int x, int y); // XX usun

    int shiftX;
    int shiftY;
    ~CoordinatsToShoot();



};
//lewo
extern CoordinatsToShoot* oneLeftPoint;
extern CoordinatsToShoot* twoLeftPoint;
//prawo
extern CoordinatsToShoot* oneRightPoint;
extern CoordinatsToShoot* twoRightPoint;
//gora
extern CoordinatsToShoot* oneUpPoint;
extern CoordinatsToShoot* twoUpPoint;
//dol
extern CoordinatsToShoot* oneDownPoint;
extern CoordinatsToShoot* twoDownPoint;
#endif // PIECETOSHOOT_H
