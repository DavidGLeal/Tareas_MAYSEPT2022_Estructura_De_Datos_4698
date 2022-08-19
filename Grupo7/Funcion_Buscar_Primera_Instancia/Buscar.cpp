/*Universidad de las Fuerzas Armadas ESPE
  Autores:
  Portilla Diego
  Valdiviezo Darwin
  Arias Sebastian
  Escobar David
  Quingaluisa Danny
  Fecha de creación: 20/05/2022
  Fecha de modificación: 20/05/2022
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Buscar.h"
#include "Nodo.h"


using namespace std;


void buscar::buscarPorCabeza(){
	int val;
	cout << "\nIngrese el valor a Buscar: ";
	cin >> val;
	int aux = 0;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->primero;
	while (tmp)
	{
		if (tmp->valor == num->valor)
		{
			aux++;
		}
		tmp = tmp->siguiente;
	}
	if (aux == 0)
	{
		cout << "El numero no existe";
	}
	else
	{
		cout << "El numero existe";
	}
}
