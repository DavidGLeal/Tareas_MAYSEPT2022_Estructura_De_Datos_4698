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
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHash.h"
#define NCASILLAS 29

using namespace std;

TablaHashCerrada::TablaHashCerrada(){
    tabla = new NodoCircular*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaHashCerrada::~TablaHashCerrada(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;
}
void TablaHashCerrada::eliminar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    while (aux == NULL)
    {
        pos++;
        aux = tabla[pos % NCASILLAS];
    }
    if(aux->getCadena() == cad){
        tabla[pos] = tabla[pos]->getSig();
        delete aux;
    }
    else
    {
	while (aux == NULL)
        {
            pos++;
            aux = tabla[pos % NCASILLAS];
        }	    
        if (aux->getSig() != NULL)
        {
            while (aux->getSig()->getCadena() != cad)
            {
                aux = aux->getSig();
            }
        }
        else cout << "No existe ese elemento. Verifique que está en la lista."<<endl;
    }
}

void TablaHashCerrada::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        cout <<" "<<"Posicion "<<i<<": ";
        int pos = i;
        aux = tabla[i];
        while(aux != NULL){
            cout << aux->getCadena() <<" ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

void TablaHashCerrada::buscar (string cad) {
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    while (aux == NULL)
    {
        pos++;
        aux = tabla[pos % NCASILLAS];
    }
    if(aux->getCadena() == cad){
        cout << "El elemento se encuentra en la posicion " << pos << endl;
    }
    else
    {
    while (aux == NULL)
        {
            pos++;
            aux = tabla[pos % NCASILLAS];
        }	    
        if (aux->getSig() != NULL)
        {
            while (aux->getSig()->getCadena() != cad)
            {
                aux = aux->getSig();
            }
        }
        else cout << "No existe ese elemento. Verifique que está en la lista."<<endl;
    }
}
int TablaHashCerrada::quadraticProbing(string cad, int i){
    int suma =0;
    int indice =0;
    suma = hash(cad);
    indice = (suma + i*i) % NCASILLAS;
    return indice;

}


void TablaHashCerrada::insertar(string cad, int opc)
{
    int i = 0;
    bool ocupado = false;
    int indice = 0;
    while (ocupado == false)
    {
         indice = quadraticProbing(cad, i);
         NodoCircular *aux = tabla[indice];
        if (tabla[indice] == NULL)
        {
            tabla[indice] = new NodoCircular(cad);
            ocupado = true;
        }
        else
        {
            i++;
        }
    }
}


int TablaHashCerrada::hash(string cad){
    int suma = 0;
    for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
    }
    return suma % NCASILLAS;
}

int TablaHashCerrada::hashDoble(string cad){

    int p = [](string cad){
    	int suma = 0;
    	for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
	    }
	    return suma % NCASILLAS;
	}(cad);
    int indice = p;
    int t = [](string cad, int p){
    	int suma = 0;
	    int indice = 0;
	    suma = p;
	    indice = 7 -( suma % 7);
	    return indice;
	}(cad,p);
    while(tabla[indice] != NULL){
        indice = indice + t;
        if(indice>NCASILLAS){
        	indice = indice%NCASILLAS;
		}
    }
    return indice;
}

void TablaHashCerrada::insertarDoble(string cad){
    int pos = hashDoble(cad);
    NodoCircular *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircular(cad);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircular(cad));
    }
}

//Sondeo Lineal
void TablaHashCerrada::insertarLineal(string cad)
{
    int i = 0;
    bool ocupado = false;
    int indice = 0;
    while (ocupado == false)
    {
         indice = hashF(cad, i);
         NodoCircular *aux = tabla[indice];
        if (tabla[indice] == NULL)
        {
            tabla[indice] = new NodoCircular(cad);
            ocupado = true;
        }
        else
        {
            i++;
        }
    }
}

int TablaHashCerrada::hashF(string cad, int i)
{
    int suma = 0;
    int indice = 0;
    suma = hash(cad);
    indice = (suma + i) % NCASILLAS; //Lineal
    return indice;
}


