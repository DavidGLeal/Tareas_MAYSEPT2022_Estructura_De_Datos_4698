#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Nodo.h"

using namespace std;
class buscar{
    public:
        void buscarPorCabeza();
    private:
        Nodo* primero;
	    Nodo* actual;
        Nodo* tmp;
	    bool listaVacia() {
		return (this->primero == NULL);
        }
};