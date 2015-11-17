#include "game.h"
#include <qdebug.h>

Game::Game(QWidget *parent)
{
    //arreglo[20][10];
    for(int y=0;y<20;y++){
           for(int x=0;x<10;x++){
               arreglo[y][x]=0;
           }
       }

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);


    player= new rect1();
    player->setRect(0,0,200,400);
    scene->addItem(player);
    scene->setSceneRect(0,0,800,600);


    do{
    arbol->llenar();
    arbol->resolver();
        if(arbol->total>0 && arbol->total<10){
            tamanos.append(arbol->total);
            qDebug()<<arbol->total;
        }
    }while(tamanos.size()<100);
    int n=tamanos.takeAt(0);



    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();



    Bullet* b=new Bullet(n);
    lista.append(b);
    scene->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();



}

