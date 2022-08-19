#include <iostream>
#include "Lista.h"

ListaEnlazada::ListaEnlazada(){

}

void ListaEnlazada::agregarFinal(int nuevo){
    Nodo *n = new Nodo(nuevo);

    if(this -> primero == nullptr)
        primero = ultimo = n;
    else{
        ultimo -> setNodo(n);
        ultimo = n;
    }
}

void ListaEnlazada::imprimirCabeza(){
    Nodo *nimpreso;
    nimpreso = primero;

    while( nimpreso != nullptr){
        cout<< nimpreso -> getValor() << " ";
        nimpreso = nimpreso->getNodo();
    }
}