#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Grafo{

    private:  
        map<int, bool> visitado;
        map<int, list<int> > adjuntados;

   public:

        void agregarNodo(int v, int w);
        void DFS(int v);
};