#include "Suma.h"

//Constructor

SumaLista::SumaLista(){
    this -> nodo = NULL;
}

void SumaLista::insertNodo(int dato){
    // Create the new Node.
    Nodo *nuevoNodo = new Nodo(dato);
    
    // Agrego a nodo
    if (nodo == NULL) {
        nodo = nuevoNodo;
        return;
    }
  
    // Llegar al final de la lista
    Nodo* temp = nodo;

    while (temp -> getNodo() != NULL) {
        // Actualizo temp
        temp = temp-> getNodo();
    }
  
    // Insertar al final
    temp -> setNodo(nuevoNodo);
}


void SumaLista::imprimirLista(){


}

int SumaLista::suma(SumaLista){

}