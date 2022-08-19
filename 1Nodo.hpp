#pragma once

template <typename T>
	
    class Nodo{
        private:
            T valor;
            Nodo<T>* nodo = nullptr;
        public:
            Nodo(T v){
                this -> valor = v;
            } 

            Nodo();

            ~Nodo(){
      
            }    

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setNodo(Nodo<T>* n){
                this -> nodo = n;
            }

            Nodo<T>* getNodo(){
                return this-> nodo;
            }
    };
