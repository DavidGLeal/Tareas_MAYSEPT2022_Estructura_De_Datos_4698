//!Plantilla de una lista Simple. Incluye nodo.h

#include <iostream>
using namespace std;
#include "Nodo.hpp"
#include <chrono>
using namespace std::chrono;

template <typename T>
    class Pila{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
            int longitud;

        public:
            Pila(){
                longitud = 0;
            }

            ~Pila(){
                free(this);
            }

            bool estaVacia(){
                return primero == nullptr;
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

            int pop(){

                int valor{0};
                if(primero == nullptr){
                    cout<< "\nStack underflow"<<endl;
                    return -1;
                }else{
                    Nodo<T> *n = primero->getNodo();
                    valor = primero->getValor();
                    primero->~Nodo();
                    primero = n;
                }

                longitud--;
                return valor;
            }

            void imprimir(){

                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    Nodo<T> *n = primero;
                    int cont = 0;
                    cout<<"\n";
                    while(n != nullptr){
                        cout<< n->getValor() << " ";
                        n = n->getNodo();
                        cont++;
                    }
                }
            }

            void binarios(long long n){

                auto start = high_resolution_clock::now();
                Pila<long long>* pn = new Pila<long long>();

                while(n != 0){
                    pn->push(n%2);
                    n = n/2;
                }

                //cout << "\n";
                while(!(pn->estaVacia())){
                    cout<< pn->pop() << " "; 
                }

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "\nTiempo de ejecucion de la funcion: "
                << duration.count() << " microsegundos" << endl;
                free(pn);
            }


            void binarioRecursivo(long long n){
               
                Pila<long long>* pn = new Pila<long long>();
                if(n >= 1){
                    binarioRecursivo(n/2);   
                    pn->push(n%2);
                }

                while(!(pn->estaVacia())){
                    cout<< pn->pop() << " "; 
                }

                free(pn);
            }
    };    