#ifndef LISTAPALABRAS_H
#define LISTAPALABRAS_H

#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
using namespace std;

struct elementos {
    char *palabra;      // Palabra
    int contador;       // Número de veces que aparece
};
// Interfaz, declaracion de la clase ListaPalabras

class ListaPalabras {
    private:
        elementos *ptrLista;    // Puntero al comienzo de la lista de palabras
        int nMaximo;            // Tamanio maximo de la lista
        int indiceActual;       // Indice del primer elemento libre de la lista
        friend class Acceso;
    public:
        ListaPalabras (int);
        int &operator[] (char *);
        void escribir_lista ();
};

#endif 