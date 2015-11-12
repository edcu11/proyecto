#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <MyRect.h>
#include <stdlib.h>

#include <QDebug>
Bullet::Bullet(int s){
    this->tam=s;
    this->p_x=s;
    this->p_y=0;

   switch(s){
   case 1:
       this->tam_g=20;
       this->setRect(0,0,this->tam_g,20);break;
   case 2:
       tam_g=40;
       this->setRect(0,0,this->tam_g,20);break;
   case 3:
       this->tam_g=60;
       this->setRect(0,0,this->tam_g,20);break;
   case 4:
        this->tam_g=80;
       this->setRect(0,0, this->tam_g,20);break;
    }

    // connect
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(500);

}

void Bullet::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(( this->p_x- this->tam)>0 &&  this->p_x<=10){
             this->setPos( this->x()-20, this->y());
             this->p_x--;
        }
    }
    else if (event->key() == Qt::Key_Right){
        if( this->p_x>=0 &&  this->p_x<10){
            this->setPos( this->x()+20, this->y());
             this->p_x++;
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
     this->p_y++;
    if (this->p_y>=9){
        this->spawn(rand() % 4 + 1);
        this->clearFocus();
        timer->stop();
    }
}
