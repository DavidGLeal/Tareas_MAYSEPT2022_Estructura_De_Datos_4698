#pragma once
#include <iostream>
#include <string>
#include "../ArbolB+/ResultadoB+.hpp"

using std::cout; 
using std::cin;
using std::endl; 
using std::string;

template <typename T>
class Vector {

    private:

        T *arrayInterno;
        int capacidad;
        int elementos{0};

        /**
         *  Implementa un equivalente al operador "<=",
         *  a partir del operador "<", que el tipo T debería soportar
         * 
         *  @param dato1 Un valor
         *  @param dato2 Otro valor
         * 
         *  @return TRUE si <code>dato1 <= dato2</code>
         */
        bool esMenorIgual(T dato1, T dato2) {
            return !(dato2 < dato1);
        }
        
        /**
         *  Implementa un equivalente al operador ">=",
         *  a partir del operador "<", que el tipo T debería soportar
         * 
         *  @param dato1 Un valor
         *  @param dato2 Otro valor
         * 
         *  @return TRUE si <code>dato1 >= dato2</code>
         */
        bool esMayorIgual(T dato1, T dato2) {
            return !(dato1 < dato2);
        }

        /**
         *  Implementa un equivalente al operador "==",
         *  a partir del operador "<", que el tipo T debería soportar
         * 
         *  @param dato1 Un valor
         *  @param dato2 Otro valor
         * 
         *  @return TRUE si "dato1 == dato2"
         */
        bool sonIguales(T dato1, T dato2) {
            return (
                this -> esMenorIgual(dato1, dato2) &&
                this -> esMayorIgual(dato1, dato2)
            );
        }

    public:
       
        /**
         * El constructor de la clase Vector toma un número entero como parámetro y crea una nueva
         * matriz del tamaño del número entero y establece la capacidad del Vector al tamaño del número
         * entero.
         * 
         * @param longitud La longitud de la matriz.
         */
        Vector(int longitud) : arrayInterno(new T[longitud]), capacidad(longitud)
        {}
        
        /**
         * El constructor predeterminado para la clase Vector.
         */
        Vector() : Vector(10)
        {}

        /**
         * El destructor se llama cuando el objeto es destruido.
         */
        ~Vector(){
            delete [] arrayInterno;
        }

        /**
         * Si la matriz está llena, duplique el tamaño de la matriz y copie la matriz anterior en la nueva
         * 
         * @param data Los datos que se agregarán al vector.
         */
        void insertarFinal(const T &data){

            if (elementos < capacidad) {
            arrayInterno[elementos] = data;
            elementos++;
            } else {
                auto tmp_arr = new T[capacidad * 2];
                capacidad *= 2;

                for (int i = 0; i < elementos; i++) {
                    tmp_arr[i] = arrayInterno[i];
                }
                delete [] arrayInterno;
                arrayInterno = tmp_arr;

                arrayInterno[elementos] = data;
                elementos++;
            }

        }

        void insertar(const T &data, int indice){

            if (elementos == capacidad){
                auto tmp_arr = new T[capacidad * 2];
                capacidad *= 2;

                for (int i = 0; i < elementos; i++) {
                    tmp_arr[i] = arrayInterno[i];
                }

                delete [] arrayInterno;
                arrayInterno = tmp_arr;
            }

            for(int i = elementos-1; i >= indice; i--){
                arrayInterno[i+1] = arrayInterno[i]; 
            }

            arrayInterno[indice] = data;
            elementos++;
        }

        void borrar(int indice){

            for(int i = indice+1; i < elementos; i++){
                arrayInterno[i-1] = arrayInterno[i]; 
            }

            eliminarFinal();
        }


        /**
         * Elimina el último elemento de la lista.
         * 
         * @return el valor de los elementos variables.
         */
        void eliminarFinal(){

            if (estVacio())
                return;
            elementos--;

        }

        /**
         * Limpia la pila.
         */
        void vaciar(){
            elementos = 0;
        }

        /**
         * Devuelve verdadero si la cola está vacía, falso en caso contrario
         * 
         * @return el valor de los elementos variables.
         */
        bool estVacio(){
            return elementos == 0;
        }

        /**
         * Devuelve el número de elementos de la lista.
         * 
         * @return El número de elementos en la lista.
         */
        int longitud(){
            return elementos;
        }

        /**
         * Devuelve el valor de la variable capacidad.
         * 
         * @return El valor de la variable capacidad.
         */
        int getCapacidad(){
            return capacidad;
        }

        /**
         * La función devuelve una referencia al elemento en la posición pos en la matriz
         * 
         * @return El elemento en la posición pos de la matriz.
         */
        T& operator[](int pos){
            if (pos >= 0 &&  pos < elementos)
                 return arrayInterno[pos];
            throw std::out_of_range("Elemento fuera de rango");
        }
        
        /**
         * Devuelve el arrayInterno.
         * 
         * @return La matriz de la clase.
         */
        T *getArrayInterno(){
            return this->arrayInterno;
        }

        /**
         * Imprime el vector
         */
        void imprimir(){
            for(int i = 0; i < elementos; i++){
                cout << this->arrayInterno[i] << " ";
            }    
        }
      
        /**
         * Toma un vector como parámetro y suma todos los elementos del vector al vector que llama la
         * función
         * 
         * @param vect El vector que se agregará al vector actual.
         */
        void unirVectores(Vector<T> &vect){
            for(int i = 0; i < vect.longitud(); i++)
                insertarFinal(vect[i]);
        }

        /**
         *  Asumiendo que el vector está ordenado, retorna la posición
         *  en la que el dato se encuentra, o debería insertarse
         * 
         *  @param dato El valor buscado
         * 
         *  @return "posicionDato" si se encuentra, y sino,
         *  "-posicionInsercion - 1"
         */
        int buscarOrdenado(T dato) {
            int i = 0;
            
            while ((i < this -> elementos) && esMayorIgual(dato, arrayInterno[i])) {
                if (sonIguales(dato, arrayInterno[i])) {
                    return i;
                }
                
                ++i;
            }
            
            return (-i - 1);
        }


        int insertarOrdenado(T dato){
            Resultado resultado(buscarOrdenado(dato));
            
            if(resultado.datoEncontrado()){
                throw std::out_of_range("Elemento repetido");
            }

            this->insertar(dato, resultado.getPosInsercion());

            return resultado.getPosInsercion();
        }

        int borrarOrdenado(T dato){
            Resultado resultado(buscarOrdenado(dato));  

            if(resultado.datoEncontrado()){
                borrar(resultado.getPosBusqueda());   
            }

            return resultado.getPosBusqueda();
        }

        void setDatos(Vector<T> &vector){
            this->vaciar();
            this->unirVectores(vector);
        }

        Vector<T>* getSubVector(int inicio, int fin){
            Vector<T>* nuevo = new Vector<T>(fin-inicio);

            for(int i = inicio; i < fin; i++){
                nuevo->insertarFinal(arrayInterno[i]);
            }

            return nuevo;
        }

        bool contiene(T dato){

            for(int i = 0; i < elementos; i++){
                if(arrayInterno[i] == dato){
                    return true;
                }
            }

            return false;
        }

        void insertarOrdenados(Vector<T> &vector){

            for(int i=0; i < vector.longitud(); i++){
                insertarOrdenado(vector[i]);
            }
        }
};

