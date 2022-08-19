#pragma once

template <typename T>
	
    class Nodo{
        private:
            T valor;
            Nodo* nodo;
        public:
            Nodo(T v){
                this -> valor = v;
                this -> nodo = nullptr;
            } 

            Nodo();

            ~Nodo(){
                free(this);
            }    

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setNodo(Nodo* n){
                this -> nodo = n;
            }

            Nodo* getNodo(){
                return this-> nodo;
            }
    };
