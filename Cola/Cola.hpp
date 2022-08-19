//!Plantilla de una lista Simple. Incluye nodo.h

#include <iostream>
using namespace std;
#include "Nodo.hpp"

template <typename T>
    class Cola{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
            int longitud;

        public:
            Cola(){
                longitud = 0;
            }

            ~Cola(){
                free(this);
            }

            bool estaVacia(){
                return primero == nullptr;
            }

            void pushLast(T v){

                Nodo<T> *n = new Nodo<T>(v);

                if(primero == nullptr){
                    primero = ultimo = n;
                }else if(primero == ultimo){
                    primero ->setNodo(n);
                    ultimo = n;
                }else{
                    ultimo-> setNodo(n);
                    ultimo = n;
                }

            }

            T poll(){

                if(primero == nullptr){
                    cout<< "\nNada que borrar. Lista vacia"<<endl;
                    return {};
                }else if(primero == ultimo){
                    T retorno {primero->getValor()};
                    primero = ultimo = nullptr;
                    return retorno;
                }else{
                    T retorno {primero->getValor()};
                    Nodo<T> *n = primero->getNodo();
                    primero->~Nodo();
                    primero = n;
                    return retorno;
                }
            }

            T peek(){

                if(primero == nullptr){
                    cout<< "\nNada que borrar. Lista vacia"<<endl;
                    return {};
                }else{
                    T retorno {primero->getValor()};
                    return retorno;
                }

            }

            void imprimir(){

                if(primero == nullptr) cout<<"\nNada que imprimir"<<endl;
                else{

                Nodo<T> *n = primero;

                cout<<"\n";
                while(n != nullptr){
                    cout<< n->getValor() << " ";
                    n = n->getNodo();
                }
                }
            }
    };    