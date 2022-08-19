/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash cerrado de enteros y strings .
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 24-06-2022
	*Fecha de modificacion:
        * 29-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/
#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Nodo.h"

using namespace std;

NodoCircular :: NodoCircular(string cad){
    cadena = cad;
    sig = NULL;
}
NodoCircular :: ~NodoCircular(){
    delete sig;
}
string NodoCircular :: getCadena(){
    return cadena;
}
NodoCircular *NodoCircular :: getSig(){
    return sig;
}
void NodoCircular :: setSig(NodoCircular *sig){
    this->sig = sig;
}

