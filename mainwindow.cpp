#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "dialog.h"
#include <QGraphicsScene>


Dialog* oknodwa;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Close");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{

    oknodwa = new Dialog();
    oknodwa->setModal(true);

    this->close();
    oknodwa->exec();
}
