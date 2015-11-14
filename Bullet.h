#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
//class arreglo;
//#include "arreglo.h"

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet(int s,int arreglo[20][10]);
    int p_y,p_x,tam,tam_g;
    int (*arreglo)[10];
    QTimer * timer;
    //int* a[20][10];
    //Arreglo* w;
    void keyPressEvent(QKeyEvent * event);
    void spawn(int t);
public slots:
    void move();
};

#endif // BULLET_H
