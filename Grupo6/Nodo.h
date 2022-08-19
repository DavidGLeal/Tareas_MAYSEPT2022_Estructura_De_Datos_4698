#ifndef NODO_H
#define NODO_H

#include<stdlib.h>
#include "Nodo.h"

class Nodo{

    private: 
    
    int dato;
    Nodo* n;
    
    public:
    // Constructor por defecto
    Nodo(){
        this -> dato = 0;
        this -> n = NULL;
    }

    Nodo(int data){
        this -> dato = data;
        this -> n = NULL;
    }

    Nodo* getNodo(){
        return this -> n;
    }

    int getDato(){
        return this -> dato;
    }
    
    void setNodo(Nodo* no){
        this -> n = no;
    }
};

#endif 