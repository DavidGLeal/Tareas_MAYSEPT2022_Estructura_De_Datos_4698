#include "Lista.h"
#include <iostream>

using namespace std;
void Lista::eliminar() {
	int val;
	cout << "\nIngrese el valor a Eliminar: ";
	cin >> val;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->primero;
	Nodo* aux = tmp;
	Nodo* final = this->actual;
	aux = tmp;
	while (aux)
	{
		if (aux->valor == num->valor)
		{
			if (aux == tmp)
			{
				*tmp = *tmp->siguiente;
			}
			else {
				final->siguiente = aux->siguiente;
			}

		}
		final = aux;
		aux = aux->siguiente;
	}
}
