#include <iostream>
#include "Grafo.cpp"

int main(){

    // Create a graph given in the above diagram
    Grafo g;
    g.agregarNodo(0, 1);
    g.agregarNodo(0, 2);
    g.agregarNodo(1, 2);
    g.agregarNodo(2, 0);
    g.agregarNodo(2, 3);
    g.agregarNodo(3, 3);
 
    cout << "Siguiendo la profundidad primero, se recorre"
            " (empezando en el vertice 2) \n";
    g.DFS(2);

    return 0;
}

