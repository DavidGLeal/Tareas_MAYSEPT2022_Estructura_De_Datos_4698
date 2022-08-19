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
#include "NodoEntero.h"

NodoCircularEntero :: NodoCircularEntero(int valor){
    this->valor = valor;
    sig = NULL;
}
NodoCircularEntero :: ~NodoCircularEntero(){
    delete sig;
}
int NodoCircularEntero :: getValor(){
    return valor;
}
NodoCircularEntero *NodoCircularEntero :: getSig(){
    return sig;
}
void NodoCircularEntero :: setSig(NodoCircularEntero *sig){
    this->sig = sig;
}
