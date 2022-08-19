#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "ListaPalabras.h"
using namespace std;

// Implementacion de las funciones miembro de la clase ListaPalabras

const int MAXIMO = 100;              // Maximo numero de elementos

// Constructor

ListaPalabras::ListaPalabras (int nElementos)
{
    // Tamanio maximo
    nMaximo = (nElementos < MAXIMO) ? nElementos: MAXIMO;
    indiceActual = 0;                       // Tamanio actual
    ptrLista = new elementos[nMaximo];      // Lista de ne elementos
}

// Buscar si existe la palabra en la lista. Si existe, retorna una
// referencia a su contador,  es decir incrementa el contador; si no
// existe, aniadirla.

int &ListaPalabras::operator[] (char *palabra)
{
    elementos *pLista1, *pLista2;

    for (pLista1 = ptrLista; pLista1 < &ptrLista[indiceActual]; pLista1++)
        if (!strcmpi (pLista1->palabra, palabra))
            return pLista1->contador;       // Existe
    if (indiceActual == nMaximo) {          // Overflow: aumentar la lista
        pLista2 = new elementos[nMaximo + 10];
        // Copiar la lista en el nuevo espacio reservado
        for (int i = 0; i < nMaximo; i++)
            pLista2[i] = ptrLista[i];
        delete ptrLista;        // Liberar el espacio ocupado por lista vieja
        ptrLista = pLista2;
        nMaximo += 10;          // Actualizar valores.
    }

    pLista1 = &ptrLista[indiceActual++];    // No existe, añadirla
    pLista1->palabra = new char[strlen (palabra) + 1];
    strcpy (pLista1->palabra, palabra);     // Almacenar la nueva palabra
    pLista1->contador = 0;                  // Valor inicial.
    return pLista1->contador;
}

// Escribir la lista

void ListaPalabras::escribir_lista ()
{
  cout << "PALABRA        CONTADOR\n";
  for (int i = 0; i < indiceActual; i++) {
    cout << setiosflags (ios::left);    // Activa indicador ajuste izquierda
    cout << setw (15) << ptrLista[i].palabra; // Establece anchura del campo a 15
    cout << resetiosflags (ios::left);  // Desactiva indicador ajuste izquierda
    cout << setw (4) << ptrLista[i].contador  // Establece anchura del campo a 4
         << endl;
  }
}