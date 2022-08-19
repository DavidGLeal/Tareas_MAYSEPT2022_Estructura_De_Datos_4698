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
#include "0Vector.cpp"
#include "2OrdenamientoInterno.cpp"
#include "6ImprimirInterno.h"
using namespace std;

class Busqueda:  public ImprimirInterno{

	private: 
		Vector vector;
		OrdenamientoInterno ordenado;
		int dato{0};
	public:

		Busqueda(){
		}

		virtual void busquedaBinaria();
		virtual void busquedaSecuencial();

		void setVector(Vector &_vector);

		void  vaciarVector();

		void  setDato(int &a);

		void copiarVector(Vector &_vector);

		void imprimirInterno();
};
