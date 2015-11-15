#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <stdlib.h>
#include "Bullet.h"
#include <qdebug.h>
#include "rect.h"
#include <qlist.h>


int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    int array[20][10];

    for(int y=0;y<20;y++){
           for(int x=0;x<10;x++){
               array[y][x]=0;
           }
       }

    QList<Bullet*>lista;


    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,800);

    rect* player = new rect(array,&lista);
    player->setRect(0,0,200,400);

    scene->addItem(player);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->spawn(rand() % 10 + 1);



    return a.exec();
}
