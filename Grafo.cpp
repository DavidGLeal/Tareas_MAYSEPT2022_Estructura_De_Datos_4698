#include "Grafo.h"
#pragma once
   
/**
 * Añade un nodo al gráfico.
 * 
 * @param v el vértice para agregar el borde a
 * @param w el nodo que se agregará a la lista de adyacencia de v
 */
void Grafo::agregarNodo(int v, int w)
{
    adjuntados[v].push_back(w);
}

/**
 * La función DFS() hace un primer recorrido en profundidad del gráfico
 * 
 * @param v El nodo inicial.
 */
void Grafo::DFS(int v)
{

    /* Imprimiendo el nodo y marcándolo como visitado. */
    visitado[v] = true;
    cout << v << " ";
 
 
    /* Una función recursiva que se utiliza para recorrer el gráfico. */
    list<int>::iterator i;
    for (i = adjuntados[v].begin(); i != adjuntados[v].end(); ++i)
        if (!visitado[*i])
            DFS(*i);
}
