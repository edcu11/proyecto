#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <rect.h>
#include <stdlib.h>
#include <QDebug>

Bullet::Bullet(int s,int arreglo[20][10]){
    this->tam=s;
    this->p_x=s;
    this->p_y=0;
    this->arreglo=arreglo;

    switch(s){
    case 1:
        this->tam_g=20;
        break;
    case 2:
        tam_g=40;
        break;
    case 3:
        this->tam_g=60;
        break;
    case 4:
         this->tam_g=80;
         break;
    case 5:
        this->tam_g=100;
        break;
    case 6:
         this->tam_g=120;
         break;
    case 7:
         this->tam_g=140;
         break;
    case 8:
         this->tam_g=160;
         break;
    case 9:
         this->tam_g=180;
         break;
    case 10:
         this->tam_g=200;
         break;
     }
    this->setRect(0,0, this->tam_g,20);
    // connect
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    if(perdio())
        qDebug("perdistes cabron");

    timer->start(150);



}

void Bullet::full()
{
    for(int cont=(this->p_x  - this->tam);cont<this->p_x;cont++){
        arreglo[this->p_y][cont]=1;
    }

}

bool Bullet::check_D()
{
    for(int cont=(this->p_x  - this->tam);cont<this->p_x;cont++){
        if(arreglo[this->p_y+1][cont]!=0)
            return true;
    }
    return false;
}

bool Bullet::check_L()
{
    if(arreglo[p_y][(p_x-this->tam)-1]==1 || ((p_x-this->tam)-1)<0)
        return false;
    else
        return true;
}

//perdio todavio no completada
bool Bullet::perdio()
{
    int pos_y=this->p_y-1;

    for(int cont=(this->p_x  - this->tam);cont<this->p_x;cont++){
        if(arreglo[pos_y+1][cont]!=0)
            return true;
    }
    return false;
}

bool Bullet::check_R()
{
    if(arreglo[p_y][p_x+1]==1 || p_x+1>10)
        return false;
    else
        return true;

}


void Bullet::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(this->check_L()){
             this->setPos( this->x()-20, this->y());
             this->p_x--;
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(this->check_R()){
            this->setPos( this->x()+20, this->y());
             this->p_x++;
        }
    }
}

void Bullet::spawn(int t)
{
    Bullet* b=new Bullet(t,this->arreglo);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}

void Bullet::move(){
    // move bullet up
    setPos(x(),y()+20);
     this->p_y++;
    if (this->check_D()){
        //this->p_y>=19
        this->full();
        for(int cont_y=0;cont_y<20;cont_y++){
            for(int cont_x=0;cont_x<10;cont_x++)
                qDebug()<<arreglo[cont_y][cont_x];
            qDebug()<<"fila "<<cont_y;
        }
        qDebug()<<"nuevo";


        this->spawn(rand() % 10 + 1);
        this->clearFocus();
        timer->stop();
    }
}
