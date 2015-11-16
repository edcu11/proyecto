#include "randomt.h"

Nodo* nodo;

RandomT::RandomT()
{

}

char RandomT::operadores()
{
    int ope=rand()%3+1;
    switch(ope){
    case 1:
        return '+';
        break;
    case 2:
        return '-';
        break;
    case 3:
        return '*';
        break;
    }
    return ' ';

}

void RandomT::llenar()
{
    nodo=new Nodo(operadores());
    nodo->izq=new Nodo(operadores());
    nodo->der=new Nodo(operadores());
    nodo->izq->izq=new Nodo(rand()%5+1);
    nodo->der->der=new Nodo(rand()%5+1);
    nodo->izq->der=new Nodo(rand()%5+1);
    nodo->der->izq=new Nodo(rand()%5+1);

}

void RandomT::resolver()
{
    int resp;
    resp=suma(nodo->val, suma(nodo->izq->val,nodo->izq->izq->val-'0',nodo->izq->der->val-'0'),
              suma(nodo->der->val, nodo->der->izq->val-'0', nodo->der->der->val-'0'));
    this->total=resp;

}

int RandomT::suma(char ope, int valor1, int valor2)
{
    switch(ope){
           case '+':
               return valor1+valor2; break;
           case '-':
               return valor1-valor2; break;
           case '*':
               return valor1*valor2; break;
       }
       return 0;
}

