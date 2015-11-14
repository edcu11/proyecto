#include "rect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include <arreglo.h>
#include <QDebug>



rect::rect(int arreglo[20][10])
{
    this->arreglo=arreglo;
}

void rect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
}

void rect::spawn(int t)
{
    Bullet* b=new Bullet(t,this->arreglo);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();
}
