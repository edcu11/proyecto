#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QDebug>
Bullet::Bullet(){
    // drew the rect
    setRect(0,0,50,20);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(500);

    p_x=10;
    p_y=10;
}

void Bullet::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
}

void Bullet::spawn()
{
    Bullet* b=new Bullet();
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}

void Bullet::move(){
    // move bullet up
    setPos(x(),y()+20);
    p_y--;
    if (p_y=0){
        scene()->removeItem(this);
        delete this;
        this->spawn();
    }
}
