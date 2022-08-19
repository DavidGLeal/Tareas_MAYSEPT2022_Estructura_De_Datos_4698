#ifndef ACCESO_H
#define ACCESO_H

#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "ListaPalabras.h"

using namespace std;

// Interfaz, declaracion de la clase Acceso

class Acceso {
    private:
        ListaPalabras *ptrActual;   // Puntero a un objeto lista
        int indice;                 // Indice actual
    public:
        Acceso (ListaPalabras &pActual);
        elementos *operator ()();   // Definicion del operador()
};

#endif 