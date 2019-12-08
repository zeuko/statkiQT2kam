#ifndef DIALOG_H
#define DIALOG_H



#include "mapa.h"
#include <QDialog>
#include "ship.h"
using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsScene* scene1;

    Map *Mapa;

};


#endif // MAP_H
