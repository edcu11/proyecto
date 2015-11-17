#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <qlist.h>
#include "rect1.h"
#include "Bullet.h"
#include "randomt.h"
#include  <QQueue>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    QList<Bullet*> lista;
    rect1* player;
    RandomT* arbol;
    int arreglo[20][10];
    QQueue<int> tamanos;



};


#endif // GAME_H
