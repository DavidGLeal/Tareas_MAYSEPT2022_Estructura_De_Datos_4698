#pragma once

template <typename T>

    class NodoDCM{
        private:
            T valor;
            NodoDCM* anterior;
            NodoDCM* siguiente;
        public:
        
            NodoDCM(T v){
                this->valor = v;
            }

            NodoDCM(){}

            ~NodoDCM(){
                delete anterior;
                delete siguiente;
            }

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setAnterior(NodoDCM* ante){
                this -> anterior = ante;
            }

            void setSiguiente(NodoDCM* sig){
                this -> siguiente = sig;
            }

            NodoDCM* getAnterior(){
                return this-> anterior;
            }

            NodoDCM* getSiguiente(){
                return this -> siguiente;
            }

    };