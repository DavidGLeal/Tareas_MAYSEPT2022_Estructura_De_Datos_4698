

#include <iostream>
using namespace std;
#include "1Nodo.hpp"
#pragma once

template <typename T>
    class Pila{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
            int longitud=0;

        public:
            Pila(){
            }

            ~Pila(){
                
            }

            bool estaVacia(){
                return primero == nullptr;
            }

            void vaciar(){

                while(longitud > 0){
                    this->pop();
                }
            }

            Nodo<T>* getPrimero(){
                return this->primero;
            }

            void setPrimero(Nodo<T>* p){
                this -> primero = p;
            }

            void push(T v){

                Nodo<T> *n = new Nodo<T>(v);

                if(primero == nullptr){
                    primero = ultimo = n;
                }else{
                    n->setNodo(primero);
                    primero = n;
                }
                longitud++;

            }

            T pop(){

                //cout<< "Entro a pop" <<endl;
                T valor;
                if(longitud == 0){
                    cout<< "\nStack underflow"<<endl;
                }else if(longitud == 1){
                    valor = primero->getValor();
                    primero = nullptr;
                    ultimo = nullptr;
                    longitud--;
                    //cout<< "Salgo de pop 1" <<endl;
                    return valor;
                }else{
                    //cout<< "Entro a condicion else pop" <<endl;
                    Nodo<T> *n = primero->getNodo();
                    valor = primero->getValor();
                    primero = nullptr;
                    primero = n;
                    longitud--;
                }

                //cout<< "salgo a pop else" <<endl;
                return valor;
            }

            void imprimir(){
                
                //cout<< "Entro funcion" <<endl;

                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    //cout<< ultimo->getValor() <<endl;
                    //cout<< "Entro" <<endl;

                    Nodo<T> *n = primero;
                    Pila<T> *pNueva = new Pila<T>();

                    while(n != nullptr){
                        pNueva->push(n->getValor());
                        n = n->getNodo();
                    }

                    //cout<< pNueva->ultimo->getValor() <<endl;

                    Nodo<T> *np = pNueva->primero;
                    cout<<"\n";

                    while(np!=nullptr){
                        cout<< pNueva->pop() << " ";
                        np = np->getNodo();
                    }

                    //cout<< "Final" <<endl;
                }
            }

            void imprimirT(){
                
                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    Nodo<T> *np = primero;

                    while(np!=nullptr){
                        cout<< np->getValor() << " ";
                        np = np->getNodo();
                    }
                    
                }
            }

            T tope(){
                return this->primero->getValor();
            }

            int getLongitud(){
                return this->longitud;
            }

            T* convertiraArray(){

                revertir();
                
                T* array = new T[longitud];
                Nodo<T> *actual = primero;
                int indice=0;
                while (actual != nullptr){
                    array[indice++] = actual -> getValor();
                    actual = actual ->getNodo();
                }

                return array;
            }

            void revertir(){
                if (estaVacia()) return;

                Nodo<T> *previo = primero;
                Nodo<T> *actual = primero -> getNodo();
            
                while(actual != nullptr){
                    Nodo<T> *siguiente  = actual ->getNodo();
                    actual -> setNodo(previo);
                    previo = actual;
                    actual = siguiente; 
                }

                ultimo = primero;
                ultimo -> setNodo(nullptr);
                primero = previo;
            
            }

    };    