/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize los diferentes tipos de ordenamientos (internos y externos) y busquedas.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 21-06-2022
	*Fecha de modificacion:
        * 28-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/

#pragma once
#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;

class Vector {

    //int es un tipo definido entero long long sin signo
    private:
        int *arrayInterno = new int[10];
        int capacidad{10};
        int elementos{0};

    public:
        Vector(){};
        ~Vector();

        void push_back(const int &data);
        void pop_back();
        void vaciar();
        bool empty();
        int size();
        int capacity();
        int& operator[](int pos);
        int *get(int);
        int getElementos();
        int *getArrayInterno();

        void imprimir(Vector *vect);
        void imprimir(Vector &vect);

        void unirVectores(Vector *vect);

};

