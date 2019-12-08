
#include "dialog.h"
#include "ui_dialog.h"
#include "mapa.h"
#include "ship.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    srand (static_cast<unsigned int>(time(nullptr)));
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene1 = new QGraphicsScene();


    ui->graphicsView->setScene(scene);

    ui->graphicsView_2->setScene(scene1);

    Map* map;

    map = new Map(20,20);
    Map* map2 = new Map(20,20);





    for(int i = 0; i < 11;i++){
        Ship* ship = Ship::createThreeMast(map);
        update();
    }
    scene->addItem(map);

    scene1->addItem(map2);

    for(int x = 0; x <9; x++)
    {

        for(int y = 0; y < 9; y++)
        {
            scene->addItem(map->getPiece(x,y));
            scene1->addItem(map2->getPiece(x,y));
        }
    }

     update();
}


Dialog::~Dialog()
{
    delete ui;
}

