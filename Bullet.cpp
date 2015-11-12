#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <MyRect.h>

#include <QDebug>
Bullet::Bullet(int s){
    this->tam=s;
    this->p_x=s;
    p_y=0;

   switch(s){
   case 1:
       tam_g=10;
       this->setRect(0,0,tam_g,20);break;
   case 2:
       tam_g=20;
       this->setRect(0,0,tam_g,20);break;
   case 3:
       tam_g=30;
       this->setRect(0,0,tam_g,20);break;
   case 4:
       tam_g=40;
       this->setRect(0,0,tam_g,20);break;
    }

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(500);

}

void Bullet::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if((p_x-tam)>0 && p_x<=10){
            setPos(x()-10,y());
            p_x--;
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(p_x>=0 && p_x<10){
            setPos(x()+10,y());
            p_x++;
        }
    }
}

void Bullet::spawn(int t)
{
    Bullet* b=new Bullet(t);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}

void Bullet::move(){
    // move bullet up
    setPos(x(),y()+20);
    p_y++;
    if (p_y>=10){
        this->spawn(4);
       // MyRect* p=new MyRect();
        //p->setRect(this->);
        scene()->removeItem(this);
        delete this;

    }
}
