
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

    Map* playersMap;

    playersMap = new Map(20,20);
    Map* botsMap = new Map(20,20,true);





    for(int i = 0; i < 4;i++){
        Ship::createOneMast(playersMap);

    }
    for(int i = 0; i < 3;i++){
        Ship::createTwoMast(playersMap);

    }
    for(int i = 0; i < 2;i++){
        Ship::createThreeMast(playersMap);

    }


    for(int i = 0; i < 4;i++){
        Ship::createOneMast(botsMap);

    }
    for(int i = 0; i < 3;i++){
        Ship::createTwoMast(botsMap);

    }
    for(int i = 0; i < 2;i++){
        Ship::createThreeMast(botsMap);

    }
    scene->addItem(playersMap);

    scene1->addItem(botsMap);

    for(int x = 0; x <10; x++)
    {

        for(int y = 0; y < 10; y++)
        {
            scene->addItem(playersMap->getPiece(x,y));
            scene1->addItem(botsMap->getPiece(x,y));
        }
    }

    update();
}


Dialog::~Dialog()
{
    delete ui;
}

