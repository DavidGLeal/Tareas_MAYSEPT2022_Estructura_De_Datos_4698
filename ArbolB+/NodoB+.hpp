#include "../Vector/Vector.hpp"
#include "ResultadoB+.hpp"

#include <iostream>
using namespace std;
#pragma once
   
template <typename T>     
class NodoBmas{
    private:

        Vector<T> datos;
        Vector<NodoBmas<T>*> hijos;
        NodoBmas<T>* siguiente{nullptr};

        bool esHoja;

    public:

        /**
         * Un constructor para la clase NodoBmas.
         * 
         * @param orden El orden del árbol B+.
         * @param esHoja Este es un valor booleano que nos dice si el nodo es un nodo hoja o no.
         */
        NodoBmas(int orden, bool esHoja) : datos(orden-1), hijos(orden), esHoja(esHoja){};

        ~NodoBmas(){}

        NodoBmas<T>* getSiguiente(){
            return this->siguiente;
        }

        void setSiguiente(NodoBmas<T>* sig){
            this->siguiente = sig;
        }

        /**
         * Retorna el valor de esHoja.
         * 
         * @return un valor booleano.
         */
        bool getEsHoja(){
            return this->esHoja;
        }

        /**
         * Devuelve verdadero si el nodo no es un nodo hoja.
         * 
         * @return El valor devuelto es un valor booleano.
         */
        bool esIntermedio(){
            return !getEsHoja();
        }

        /**
         * Comprueba si la pila está vacía.
         * 
         * @return un valor booleano.
         */
        bool estaVacio(){
            return this->datos.estVacio();
        }

        /**
         * Devuelve el número de elementos de la lista.
         */
        int cantidadDatos(){
            return this->datos.longitud();
        }

        /**
         * Devuelve el número de hijos del nodo.
         */
        int cantidadHijos(){
            return this->hijos.longitud();
        }

        //Retorna una instancia de resultado, que almacena un indice 
        //util para poder encontrar el lugar en donde insertarlo
        Resultado buscadorNodo(T v){
            return Resultado(datos.buscarOrdenado(v));
        }

        Vector<T> &getDatos(){
            return this->datos;
        }

        Vector<NodoBmas<T>*> &getHijos(){
            return this->hijos;
        }

        int insertarOrdenado(T dato){
            return datos.insertarOrdenado(dato);
        }

        void insertarOrdenado(T dato, NodoBmas<T>* hijoActual){
            int posInsertada{this->insertarOrdenado(dato)};

            if(posInsertada < cantidadHijos()){
                posInsertada++;
            }

            hijos.insertar(hijoActual, posInsertada);

        }

        bool tieneHermanoDer (int posHijo) {
		    return (posHijo < (hijos.longitud() - 1));
	    }

        
        bool tieneHermanoIzq (int posHijo) {
		    return (posHijo > 0);
	    }

        NodoBmas<T> *getHermanoIzq (int posHijo) {
            return this->getHijos()[posHijo + (tieneHermanoIzq(posHijo) ? -1 : 1)];
	    }

        NodoBmas<T> *getHermanoDer (int posHijo) {
		    return this->getHijos()[posHijo + (tieneHermanoDer(posHijo) ? 1 : -1)];
	    }

        bool tieneHijoIzquierdo(int pos) {
            return (pos > 0);
        }

        int getPosSepar (int posHijo, NodoBmas<T> *hermano) {

            if (!tieneHermanoIzq(posHijo))
                return 0;
            
            if (!tieneHermanoDer(posHijo))
                return (hijos.longitud() - 2);
            
            if (getHermanoIzq(posHijo) == hermano)
                return (posHijo - 1);
            
            if (getHermanoDer(posHijo) == hermano)
                return posHijo;
            
            throw std::out_of_range("No se pudo determinar el índice a retornar"); 
            
	    }

        void ordenarHijos (Vector<NodoBmas<T>*> &lista) {
            Vector<NodoBmas<T>*> salida(lista.longitud());
            
            for(int i = 0; i < hijos.longitud(); i++){

                if(lista.contiene(hijos[i])){
                    salida.insertarFinal(hijos[i]);
                }

            }

            lista.setDatos(salida);

	    }

};
    
