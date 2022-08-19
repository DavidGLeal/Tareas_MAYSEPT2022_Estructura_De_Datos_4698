#pragma once

template <typename T>
	
    class Nodo{
        private:
            T valor;
            Nodo* nodo;
        public:
            /**
             * Nodo(T v) es un constructor que toma un valor de tipo T y establece el valor del nodo en
             * ese valor y establece el siguiente nodo en nullptr
             * 
             * @param v el valor del nodo
             */
            Nodo(T v){
                this -> valor = v;
                this -> nodo = nullptr;
            } 

            Nodo() {}

            ~Nodo(){
            }    

            /**
             * Establece el valor de la variable valor al valor del parámetro v.
             * 
             * @param v el valor a ser almacenado en el nodo
             */
            void setValor(T v){
                this -> valor = v;
            }

           /**
            * Devuelve el valor de la variable valor.
            * 
            * @return El valor del nodo.
            */
            T getValor(){
                return this->valor;
            }

            /**
             * Establece el nodo de la clase en el nodo pasado como parámetro.
             * 
             * @param n el nodo a configurar
             */
            void setNodo(Nodo* n){
                this -> nodo = n;
            }

            /**
             * Devuelve el nodo.
             * 
             * @return el nodo
             */
            Nodo* getNodo(){
                return this-> nodo;
            }
    };
