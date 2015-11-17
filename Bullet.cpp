#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <rect1.h>
#include <stdlib.h>
#include <QDebug>
#include <randomt.h>
#include "game.h"
#include <typeinfo>

extern Game* game;
Bullet::Bullet(int s){
    this->tam=s;
    this->p_x=s;
    this->p_y=0;

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
    timer->start(150);



}

void Bullet::full()
{
    for(int cont=(this->p_x  - this->tam);cont<this->p_x;cont++){
        game->arreglo[this->p_y][cont]=1;
    }
}

bool Bullet::check_D()
{

    if(this->tam==1 && this->p_y>=19){
        if(game->arreglo[this->p_y+1][this->p_x]==1)
            return false;
        else
            return true;
    }

    for(int cont=(this->p_x  - this->tam);cont<this->p_x;cont++){
        if(game->arreglo[this->p_y+1][cont]!=0)
            return true;
    }
    return false;
}

bool Bullet::check_L()
{
    if(game->arreglo[p_y][(p_x-this->tam)-1]==1 || ((p_x-this->tam)-1)<0)
        return false;
    else
        return true;
}

bool Bullet::check_Fila()
{
    for(int c=0;c<10;c++){
        if(game->arreglo[this->p_y][c]==0)
            return false;
    }
    return true;
}

int Bullet::fila_faltante()
{
    bool vacio=true;
    for(int fila=20;fila>0;fila--){
        for(int c=0;c<10;c++){
            if(game->arreglo[fila][c]==1)
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
    if(game->arreglo[1][0]==1)
        return true;
    return false;
}

void Bullet::clean_arreglo(int valor_y)
{
    for(int c=0;c<10;c++)
        game->arreglo[valor_y][c]=0;
}

void Bullet::act_A(int valor_y, int valor_p)
{
    if(valor_p>0){
        for(int c=0;c<10;c++){
            game->arreglo[valor_y][c]=game->arreglo[valor_p][c];
        }
        act_A(valor_p,--valor_p);
        //return;
    }

}

void Bullet::act_L(int valor_y)
{
    int menor=19;
    for(int cont=0;cont<game->lista.size();cont++){
        if(game->lista.at(cont)->p_y<valor_y){
            game->lista.at(cont)->p_y++;
            act_Alturas(game->lista.at(cont));
            if(menor<game->lista.at(cont)->p_y)
            menor=game->lista.at(cont)->p_y;
        }
    }
    clean_arreglo(menor);
}

void Bullet::act_Alturas(Bullet *b)
{
    b->setPos(b->x(),b->y()+20);


}



Bullet* Bullet::buscar(int valor_y)
{
    for(int c=0;c<game->lista.size();c++){
        if(game->lista.at(c)->p_y==valor_y){
            Bullet* temp=game->lista.takeAt(c);
            return temp;
        }
    }
    return NULL;
}

bool Bullet::check_R()
{
    if(game->arreglo[p_y][p_x+1]==1 || p_x+1>10)
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
    Bullet* b=new Bullet(t);
    game->lista.append(b);
    scene()->addItem(b);
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();


    for(int c=0; c<4;c++){
        game->sigs[c]->actualizar(game->sigs[c+1]->valor);
    }
    QString ecua=game->ecuaciones.first();
    game->ecuaciones.removeFirst();
    game->sigs[4]->actualizar(ecua);
}


void Bullet::move(){

    setPos(x(),y()+20);
    this->p_y++;


    if (this->check_D()){
        this->full();

   // rand()%10+1
        this->spawn(game->tamanos.first());
        game->tamanos.removeFirst();
        game->ecuaciones.removeFirst();
        this->clearFocus();
        timer->stop();

        if(check_Fila()){
            Bullet* temp=buscar(this->p_y);
            while(temp!=NULL){
                scene()->removeItem(temp);
                temp=buscar(this->p_y);
            }
            delete temp;
            act_A(this->p_y,this->p_y-1);
            act_L(this->p_y);
            game->pnts+=10;
            game->score->actualizar(QString("Score: ")+QString::number(game->pnts));
        }
    }
}
