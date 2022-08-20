#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Nodo.h"

NodoCircular :: NodoCircular()
{
    dato = "";
    siguiente = nullptr;
}
NodoCircular :: NodoCircular(std::string _dato){
    dato = _dato;
    siguiente = nullptr;
}
NodoCircular::~NodoCircular(){
    delete siguiente;
}
std::string NodoCircular::getDato(){
    return dato;
}
void NodoCircular::setDato(std::string _dato){
    dato = _dato;
}
NodoCircular* NodoCircular::getSiguiente(){
    return siguiente;
}
void NodoCircular :: setSiguiente(NodoCircular* _siguiente){
    siguiente = _siguiente;
}