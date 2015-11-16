#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <rect.h>
#include <stdlib.h>
#include <QDebug>
#include <randomt.h>

Bullet::Bullet(int s,int arreglo[20][10], QList<Bullet*>* lista){
    this->tam=s;
    this->p_x=s;
    this->p_y=0;
    this->arreglo=arreglo;
    this->lista=lista;


    switch(s){
    case 1:
        this->tam_g=20;
        this->setBrush(Qt::darkGray);
        break;
    case 2:
        tam_g=40;
        this->setBrush(Qt::red);
        break;
    case 3:
        this->tam_g=60;
        this->setBrush(Qt::cyan);
        break;
    case 4:
         this->tam_g=80;
        this->setBrush(Qt::darkCyan);
         break;
    case 5:
        this->tam_g=100;
        this->setBrush(Qt::darkBlue);
        break;
    case 6:
         this->tam_g=120;
        this->setBrush(Qt::darkMagenta);
         break;
    case 7:
         this->tam_g=140;
        this->setBrush(Qt::blue);
         break;
    case 8:
         this->tam_g=160;
        this->setBrush(Qt::darkBlue);
         break;
    case 9:
         this->tam_g=180;
        this->setBrush(Qt::yellow);
         break;
    case 10:
         this->tam_g=200;
        this->setBrush(Qt::green);
         break;
     }
    this->setRect(0,0, this->tam_g,20);
    // connect
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    this->lista->append(this);

   /* if(fila_faltante()!=-1){
        int fila=fila_faltante();
        act_A(fila,fila-1);
        act_L(fila);
    }

    if(perdio()){
        qDebug("perdistes cabron");
        for(int c=0;c<lista->size();c++){
            scene()->removeItem(lista->at(c));
        }
        for(int c=0;c<20;c++){
            for(int f=0;f<10;f++)
                arreglo[c][f]=0;
        }
    }*/
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
    /*
    if(this->tam==1 && this->p_y>=18){
        if(arreglo[this->p_y+1][this->p_x]!=0)
            return true;
        else
            return false;
    }*/

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

bool Bullet::check_Fila()
{
    for(int c=0;c<10;c++){
        if(arreglo[this->p_y][c]==0)
            return false;
    }
    return true;
}

int Bullet::fila_faltante()
{
    bool vacio=true;
    for(int fila=20;fila>0;fila--){
        for(int c=0;c<10;c++){
            if(arreglo[fila][c]==1)
                vacio=false;
       }
       //si sale del for sin encontrar 1 es porque esta vacia la fila
       if(vacio)
           return fila;
   }
   return -1;
}

//perdio todavio no completada
bool Bullet::perdio()
{
    if(arreglo[1][0]==1)
        return true;
    return false;
}

void Bullet::clean_arreglo(int valor_y)
{
    for(int c=0;c<10;c++)
        arreglo[valor_y][c]=0;
}

void Bullet::act_A(int valor_y, int valor_p)
{
    if(valor_p>0){
        for(int c=0;c<10;c++){
            arreglo[valor_y][c]=arreglo[valor_p][c];
        }
        act_A(valor_p,--valor_p);
        //return;
    }

}

void Bullet::act_L(int valor_y)
{
    if(valor_y-1>=0){
        Bullet* tempo=buscar(valor_y-1);
        while(tempo!=NULL){
            tempo->p_y+=1;
            tempo->setPos(tempo->x(),tempo->y()+20);
            tempo=buscar(valor_y-1);
        }
        if(tempo==NULL){
            this->clean_arreglo(valor_y-1);
            return;
        }
        act_L(valor_y-1);
    }
   // this->clean_arreglo(valor_y);
}



Bullet* Bullet::buscar(int valor_y)
{
   // QList<Bullet*>::iterator i;
    for(int c=0;c<lista->size();c++){
        if(lista->at(c)->p_y==valor_y){
            Bullet* temp=lista->takeAt(c);
            return temp;
        }
    }
    return NULL;
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
    Bullet* b=new Bullet(t,this->arreglo,this->lista);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();

}


void Bullet::move(){
    // move bullet up
    setPos(x(),y()+20);
    this->p_y++;
    if (this->check_D()){
        this->full();
        RandomT* arbol=new RandomT();

        do{
        arbol->llenar();
        arbol->resolver();
        qDebug()<<arbol->total;
        }while(arbol->total>10 || arbol->total<=0);

        this->spawn(arbol->total);
        this->clearFocus();
        timer->stop();

        if(check_Fila()){
            Bullet* temp=buscar(this->p_y);
            while(temp!=NULL){
                scene()->removeItem(temp);
                temp=buscar(this->p_y);
            }
            delete temp;
            qDebug()<<this->y();
            act_A(this->p_y,this->p_y-1);
            qDebug("ultimoact");
            act_L(this->p_y);
            qDebug("priemr act");


        }

    }
}
