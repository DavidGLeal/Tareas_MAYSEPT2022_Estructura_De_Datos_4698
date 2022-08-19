#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "Acceso.h"
using namespace std;
// Implementacion de las funciones miembro de la clase Acceso

// Constructor de la clase Acceso
Acceso::Acceso (ListaPalabras &pActual)
{
    ptrActual = &pActual;
    indice = 0;
}

// Definicion del operador()

elementos *Acceso::operator ()()
{
    return (indice < ptrActual->indiceActual) ?
            &ptrActual->ptrLista[indice++] : NULL;
}