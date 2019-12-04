#include "dialog.h"
#include "ui_dialog.h"
#include "mapa.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene1 = new QGraphicsScene();


    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene1);
    scene->addItem(new Map(20, 20));


    scene1->addItem(new Map(20, 20));

}


Dialog::~Dialog()
{
    delete ui;
}
