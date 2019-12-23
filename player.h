#ifndef PLAYER_H
#define PLAYER_H
#include "mapa.h"
#include <QObject>
using namespace std;

class Player : public QObject
{
    Q_OBJECT
public:

    Player();
    ~Player();
    bool takeTurn(Map *map);

};

#endif // PLAYER_H
