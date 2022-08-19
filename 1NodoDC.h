/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#pragma once
#include "2ItoString.h"

template <typename T>

    class NodoDC: public ToString{
        private:
            T valor;
            NodoDC* anterior;
            NodoDC* siguiente;
        public:


            /**
             * @param v
             */
            NodoDC(T v){
                this->valor = v;
            }

            NodoDC(){}

            ~NodoDC(){
                delete anterior;
                delete siguiente;
            }

            /**
             * @param v
             * @return setValor
             */
            void setValor(T v){
                this -> valor = v;
            }

            /**
             * @param v
             * @return setValor
             */
            T getValor(){
                return this->valor;
            }

            /** @param ante
            * @return setAnterior
            */
            void setAnterior(NodoDC* ante){
                this -> anterior = ante;
            }   

            /**
             * @param sig
             * @return setSiguiente
             */
            void setSiguiente(NodoDC* sig){
                this -> siguiente = sig;
            }


            /**
             * @return getAnterior
             */
            NodoDC* getAnterior(){
                return this-> anterior;
            }

            /**
             * @return getSiguiente
             */
            NodoDC* getSiguiente(){
                return this -> siguiente;
            }

            /**
            * @return getSiguiente
            
            */
            string toString(){
                return valor->toString();
            }
            

    };