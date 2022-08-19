#include <iostream>
#include "../ColaPila/Pila.hpp"
#include "NodoB+.hpp"
using namespace std;
#pragma once
   
template <typename T>      
class Camino{
    private:
        Pila<NodoBmas<T>*> nodos;
        Pila<int> indices;
        bool datoEncontrado{false};

    public:

        /**
         * Agrega un nodo a la cola.
         * 
         * @param nodo El nodo que se agregará a la cola.
         */
        void agregarNodo(NodoBmas<T>* nodo){
            nodos.push(nodo);
        }

        /**
         * Devuelve el siguiente nodo en la pila y luego elimina ese elemento de
         * la misma.
         * 
         * @return El primer elemento de la pila.
         */
        NodoBmas<T>* siguienteNodo(){
            if(nodos.estaVacio())
                return nullptr;
            
            return nodos.pop();
        }

        /**
         * Devuelve el elemento superior de la pila.
         * 
         * @return La parte superior de la pila.
         */
        NodoBmas<T>* getNodoActual(){
            if(nodos.estaVacio())
                return nullptr;

            return nodos.peek();
        }
        
        
        /**
         * Agrega un índice a la pila.
         * 
         * @param indice El índice del vértice en la matriz de vértices.
         */
        void agregarIndice(int indice){
            indices.push(indice);
        }

        /**
         * Devuelve el valor del elemento superior de la pila `índices` y luego elimina ese elemento de
         * la pila
         * 
         * @return El índice del siguiente elemento en la matriz.
         */
        int siguienteIndice(){
            return indices.pop();
        }

        /**
         * Devuelve el elemento superior de la pila.
         * 
         * @return La parte superior de la pila.
         */
        int getIndiceActual(){
            return indices.peek();
        }

        /**
         * Esta función marca los datos como encontrados
         */
        void marcarDatos(){
            this->datoEncontrado = true;
        }

        /**
         * Devuelve el valor de la variable datoEncontrado.
         * 
         * @return El valor de la variable datoEncontrado.
         */
        bool getEncontreDato(){
            return this->datoEncontrado;
        }

        /**
         * Comprueba si la lista está vacía.
         * 
         * @return un valor booleano.
         */
        bool fin(){
            return nodos.estaVacio();
        }



};