#pragma once
#include "2ItoString.h"

template <typename T>

    class NodoDC: public ToString{
        private:
            T valor;
            NodoDC* anterior;
            NodoDC* siguiente;
        public:
        
            NodoDC(T v){
                this->valor = v;
            }

            NodoDC(){}

            ~NodoDC(){
                delete anterior;
                delete siguiente;
            }

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setAnterior(NodoDC* ante){
                this -> anterior = ante;
            }

            void setSiguiente(NodoDC* sig){
                this -> siguiente = sig;
            }

            NodoDC* getAnterior(){
                return this-> anterior;
            }

            NodoDC* getSiguiente(){
                return this -> siguiente;
            }

            string toString(){
                return valor->toString();
            }

    };