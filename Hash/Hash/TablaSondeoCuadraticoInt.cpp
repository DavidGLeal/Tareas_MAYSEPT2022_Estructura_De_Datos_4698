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
#include "TablaSondeoCuadraticoInt.h"


TablaSondeoCuadraticoInt::TablaSondeoCuadraticoInt() : TablaCerradaEnteros()
{
    i=1;
}

TablaSondeoCuadraticoInt::~TablaSondeoCuadraticoInt()
{

}

int TablaSondeoCuadraticoInt::hash2(int pos)
{
	int suma =0;
    int indice =0;
    suma = hash(tabla[pos]->getValor());
    indice = (pos + i*i) % NCASILLAS;
    i++;
	return indice;
}