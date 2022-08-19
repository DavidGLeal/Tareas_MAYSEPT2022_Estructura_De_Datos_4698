#pragma once
#include <iostream>
#include "Rivera.h"
using namespace std;

void Shell::ordenarShell(Vector *v){
    int j, incremento, aux; // incremento: Tamaño del bloque de separación de los elementos dentro del método Shell.
    incremento = v->getElementos() / 2; // De acuerdo al algoritmo original, el incremento se divide en 2 en cada iteración.
    while (incremento > 0)
    {
        for (int i = incremento; i < v ->size(); i++)
        {
            j = i - incremento; // j es un índice de secuenciamiento.
            while (j >= 0)
            {
                if ((*v)[j] >= (*v)[j + incremento]) // Se comparan los elementos distales a un factor incremental de separación.
                {
                    aux = (*v)[j]; // Se intercambian los valores, logrando el ordenamiento.
                    (*v)[j] =  (*v)[j + incremento];
                    (*v)[j + incremento] = aux;
                }
                else
                {
                    j = 0; // Se retrocede el índice de secuenciamiento del vector.
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2; // Se divide el bloque de comparación en cada iteración.
    }
}

Vector* Shell::dividir(Vector &v, int comienzo, int ran){
    Vector *a = new Vector();

    for(int i = comienzo; i < ran; i++){
        a->push_back(v[i]);
    }

    return a;
}

void Shell::generarRandom(Vector &v, int tam){
    long long int RND{0};

    for (int i = 0; i < tam; i++)
    {
        do
        {
            RND = rand() % 1000 + 1;
        } while (RND < 0 || RND > 100);
        v.push_back(RND);
    }
}

void Shell::rango(Vector &v, int ran){
    Vector ordenado;
    int max{v.getElementos()%ran};
    int min(floor(v.getElementos()/ran));
    int multi{0};
    int tope{ran};

    for(int y = 0; y < min; y++){

        Vector *aux = dividir(v, multi, tope);
        ordenarShell(aux);
        multi += ran;
        tope += ran;

        for(int o = 0; o < aux->getElementos(); o++){
            ordenado.push_back((*aux)[o]);
        }
    }

    Vector *aux2 = new Vector();
    for(int e = multi; e < multi+max; e++){        
        aux2->push_back(v[e]); 
    }    

    ordenarShell(aux2);

    for(int j = 0; j < aux2->getElementos(); j++){
        ordenado.push_back((*aux2)[j]);
    }

    cout << "\n";
    cout << "Ordenado con rango de " << ran <<endl;
    ordenado.imprimir(ordenado);
}