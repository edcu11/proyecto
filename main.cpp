#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,800);

    MyRect* player = new MyRect();
    player->setRect(0,0,200,200);

    scene->addItem(player);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->spawn(1);

   // QTimer * timer = new QTimer();
    //QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    //timer->start(10000);

    return a.exec();
}
