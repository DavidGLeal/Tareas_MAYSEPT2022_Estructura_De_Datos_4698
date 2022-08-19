#pragma once

template <typename T>

    class NodoD{
        private:
            T valor;
            NodoD* anterior;
            NodoD* siguiente;
        public:
            NodoD(T v){
                this->valor = v;
                this->anterior = nullptr;
                this->siguiente = nullptr;
            }

            NodoD(){}

            ~NodoD(){
                delete &anterior;
                delete &siguiente;
            }

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setAnterior(NodoD* ante){
                this -> anterior = ante;
            }

            void setSiguiente(NodoD* sig){
                this -> siguiente = sig;
            }

            NodoD* getAnterior(){
                return this-> anterior;
            }

            NodoD* getSiguiente(){
                return this -> siguiente;
            }

    };