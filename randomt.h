#ifndef RANDOMT_H
#define RANDOMT_H

#include <queue>
#include <nodo.h>
#include <stdlib.h>
class RandomT
{
public:
    RandomT();
    char a[7];
    int total;
    char operadores();
    void llenar();
    void resolver();
    int suma(char ope,int valor1, int valor2);



};

#endif // RANDOMT_H
