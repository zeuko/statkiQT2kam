#ifndef PLAYER_H
#define PLAYER_H
#include "mapa.h"

using namespace std;

class player
{
public:
    player();
    ~player();
    void fireToMap();


    void checkPlayerShot();
private:
    vector<vector<Piece*>> piecePlayer;
};

#endif // PLAYER_H
