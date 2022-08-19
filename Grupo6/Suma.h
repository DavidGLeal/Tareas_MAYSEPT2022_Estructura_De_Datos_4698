#ifndef SUMA_H
#define SUMA_H

#include "Nodo.h"
#include <iostream>

class SumaLista{
    
    private:
    Nodo* nodo;

    public:
        
        SumaLista();
        void insertNodo(int);
        void imprimirLista();
        int suma(SumaLista);
};

#endif 