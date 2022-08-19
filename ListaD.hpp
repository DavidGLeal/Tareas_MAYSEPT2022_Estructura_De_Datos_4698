#pragma once
#include <iostream>
#include "NodoD.hpp"
#include "Insertar.hpp"
#include "Eliminar.hpp"
#include "Buscar.hpp"

using namespace std;

template <typename T>
    class ListaDoble: public Insertar<T>, public Eliminar<T>, public Buscar<T>{

        private:
            NodoD<T> *primero = nullptr;
            NodoD<T> *ultimo = nullptr;
            int longitud;

            bool estaVacio(){
                return primero == nullptr;
            }

            bool indiceOFL(int indice){
                return indice >= longitud  || indice < 0;
            }

        public:
            ListaDoble(){
                longitud = 0;
            }

            ~ListaDoble(){
                primero-> ~NodoD();
                ultimo-> ~NodoD();
            }

            void insertarInicio(T v){

                if(estaVacio()){
                    cout<< "Lista vacia. Utiliza la funcion insertar para comenzar"<<endl;
                    return;
                }else{
                    NodoD<T> *nuevo = new NodoD<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(nullptr);
                        nuevo->setSiguiente(primero);
                        //Recorro direccion del nodo existente
                        primero->setAnterior(nuevo);
                        //Asigno nuevos iteradores
                        primero = nuevo;

                    longitud++;
                }
            }

            void insertarFinal(T v){

                if (estaVacio()){
                    cout<< "Lista vacia. Utiliza la funcion insertar para comenzar"<<endl;
                    return;
                }else{
                    NodoD<T> *nuevo = new NodoD<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(ultimo);
                        nuevo->setSiguiente(nullptr);
                        //Recorro direccion del nodo existente
                        ultimo->setSiguiente(nuevo);
                        //Asigno nuevos iteradores
                        ultimo = nuevo;

                    longitud++;
                }               
            }

            void insertar(int indice, T v){

                if(indiceOFL(indice)){
                    cout <<"La lista no posee tantos elementos, o no es de longitud negativa" <<endl;
                    return;
                }else{
                    
                    if(indice == 0){
                        insertarInicio(v);
                    
                    }else{    

                        NodoD<T> *nuevo = new NodoD<T>(v);
                        NodoD<T> *iterador = primero;

                        while(indice != 0){
                            iterador = iterador->getSiguiente();
                            indice--;
                        }    
                        
                        //Conecto nodo nuevo en donde se solicito
                        nuevo->setAnterior(iterador->getAnterior());
                        nuevo->setSiguiente(iterador);

                        //Conecto los nodos de la lista al nodo nuevo
                        (iterador->getAnterior())->setSiguiente(nuevo);
                        iterador->setAnterior(nuevo);
                    }

                    longitud++;
                }
            }

            void insertar(T v){
                if(longitud == 0){
                    NodoD<T> *nuevo = new NodoD<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else cout<<"Cuidado. Su lista ya posee nodos" <<endl;
            }

            void eliminarInicio(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{

                    if(primero == ultimo){
                        primero = ultimo = nullptr;
                    }else{
                        NodoD<T> *segundo = primero->getSiguiente();
                        primero = nullptr; //Elimino referencia
                        primero = segundo;
                        segundo -> setAnterior(nullptr);    
                    }
                    
                    longitud--;
                }
            }

            void eliminarFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{
                    if(primero == ultimo){
                        primero = ultimo = nullptr;
                    }else{
                        NodoD<T> *previo = ultimo->getAnterior();
                        ultimo = nullptr;
                        ultimo = previo;
                        ultimo->setSiguiente(nullptr);
                    }   
                    longitud--;
                }
            }

            void eliminar(int indice){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{

                    if(indiceOFL(indice)) cout <<"La lista no posee tantos elementos, o es de longitud negativa" <<endl;
                    else{
                        if(indice == 0){
                            eliminarInicio();

                        }else{   

                            NodoD<T> *iterador = primero;

                            while(indice != 0){
                                iterador = iterador->getSiguiente();
                                indice--;
                            } 

                            if(iterador->getSiguiente() ==  nullptr){
                                eliminarFinal();
                            }else{
                                NodoD<T> *previo;
                                NodoD<T> *siguiente;

                                previo = iterador->getAnterior();
                                siguiente = iterador->getSiguiente();

                                previo->setSiguiente(siguiente);
                                siguiente->setAnterior(previo);

                                delete &iterador;
                            }   
                        }

                        longitud--;
                    }
                }
            }

            void imprimirInicio(){

                if (estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{

                    NodoD<T> *nimpreso;
                    nimpreso = primero;

                    cout << "\nNULL <- ";
                    while( nimpreso != nullptr){

                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();

                        if(nimpreso != nullptr){
                            cout<< " <-> ";
                        }else{
                            cout<< " -> "; 
                        }
                    }
                    cout << " NULL" <<endl;
                }
            }

            void imprimirFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada imprimir"<<endl;
                else{
                    
                    NodoD<T> *nimpreso;
                    nimpreso = ultimo;

                    cout << "\nNULL <- ";
                    while( nimpreso != nullptr){

                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getAnterior();

                        if(nimpreso != nullptr){
                            cout<< " <-> ";
                        }else{
                            cout<< " -> "; 
                        }
                    }
                    cout << " NULL" <<endl;
                }
            }

            int buscar(T buscado){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{
                    NodoD<T> *iterador = primero;
                    int indice = 0;
                    while( iterador != nullptr){
                        if(iterador->getValor() == buscado) return indice;
                        iterador = iterador->getSiguiente();
                        indice++;   
                    }
                }
                return -1;
            }

            void imprimirBuscar(T buscado){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{

                    if(buscar(buscado) == -1){
                        cout<< "No se encontro su instancia en la lista"<<endl;
                    }else{
                        cout<< "La primera instancia de valor "<< buscado << " se encuentra en el indice "<< buscar(buscado)<<endl;
                    }    
                }
            }

            void revertir(){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que revertir"<<endl;
                else{
                    ListaDoble<T> *revertida = new ListaDoble<T>();
                    NodoD<T> *iterador = ultimo;

                    revertida->insertar(iterador->getValor());
                    iterador = iterador->getAnterior();

                    while(iterador != nullptr){
                        revertida->insertarFinal(iterador->getValor());
                        iterador = iterador->getAnterior();
                    }

                    this->primero = revertida->primero;
                    this->ultimo = revertida->ultimo;
                    revertida = nullptr;
                }
            }
    };