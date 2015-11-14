#include <myrect.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include <arreglo.h>
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
}

void MyRect::spawn(int t, Arreglo* a)
{
    Bullet* b=new Bullet(t,a);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}

