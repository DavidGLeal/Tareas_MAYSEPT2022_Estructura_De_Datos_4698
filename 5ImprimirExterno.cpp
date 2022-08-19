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
#include "5ImprimirExterno.h"

//! FUNCION IMPRIMIR
void ImprimirExterno::imprimir(string nombre)
{
  fstream F;
  F.open(nombre, ios::in);
  int dato{0};
  F >> dato;

  while (!F.eof())
  {
    cout << dato << " ";
    F >> dato;
  }

  F.close();
}

