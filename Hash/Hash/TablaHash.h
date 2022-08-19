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
#define NCASILLAS 29

class TablaHashCerrada{
    private:
        NodoCircular **tabla;
        string dato;
    public:
        TablaHashCerrada();
        ~TablaHashCerrada();
        void insertar(string cad,int opc);
        void eliminar(string cad);
        void imprimir();
        void buscar(std::string valor);
        int hash(string cad); 
        int quadraticProbing(string cad , int i);
        int hashDoble(string cad); 
        void insertarLineal(string cad);
        int hashF(string cad, int i);
        void insertarDoble(string cad);   
};
