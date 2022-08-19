#pragma once

#include <iostream>
#include "7NodoDC.hpp"
#include "2IInsertar.h"
#include "2IEliminar.h"
#include "2IBuscar.h"

using namespace std;

template <typename T>
    class ListaDobleCM: public Insertar<T>, public Eliminar<T>, public Buscar<T>{

        private:
            NodoDCM<T> *primero = nullptr;
            NodoDCM<T> *ultimo = nullptr;
            int longitud;

            bool indiceOFL(int indice){
                return indice >= longitud  || indice < 0;
            }

        public:
            ListaDobleCM(){
                longitud = 0;
            }

            ~ListaDobleCM(){
                primero-> ~NodoDCM();
                ultimo-> ~NodoDCM();
            }
            
            bool estaVacio(){
                return primero == nullptr;
            }


            NodoDCM<T>* getPrimero(){
                return this->primero;
            }

            
            NodoDCM<T>* getUltimo(){
                return this->ultimo;
            }

            void insertarInicio(T v){

                if(longitud == 0){
                    NodoDCM<T> *nuevo = new NodoDCM<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else if(estaVacio()){
                    cout<< "Lista vacia. Utiliza la funcion insertar para comenzar"<<endl;
                    return;
                }else{
                    NodoDCM<T> *nuevo = new NodoDCM<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(ultimo);
                        nuevo->setSiguiente(primero);
                        //Recorro direccion del nodo existente
                        primero->setAnterior(nuevo);
                        //Asigno nuevos iteradores
                        primero = nuevo;

                    longitud++;
                }
            }

            void insertarFinal(T v){

                if(longitud == 0){
                    NodoDCM<T> *nuevo = new NodoDCM<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else if (estaVacio()){
                    cout<< "Lista vacia. Utiliza la funcion insertar para comenzar"<<endl;
                    return;
                }else{
                    NodoDCM<T> *nuevo = new NodoDCM<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(ultimo);
                        nuevo->setSiguiente(primero);
                        //Recorro direccion del nodo existente
                        ultimo->setSiguiente(nuevo);
                        //Asigno nuevos iteradores
                        ultimo = nuevo;

                    longitud++;
                }               
            }

            void insertar(T v, int indice){

                if(longitud == 0){
                    NodoDCM<T> *nuevo = new NodoDCM<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else if(indiceOFL(indice)){
                    cout <<"La lista no posee tantos elementos, o no es de longitud negativa" <<endl;
                    return;
                }else{
                    
                    if(indice == 0){
                        insertarInicio(v);
                    
                    }else{    

                        NodoDCM<T> *nuevo = new NodoDCM<T>(v);
                        NodoDCM<T> *iterador = primero;

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


            void eliminarInicio(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{

                    if(primero == ultimo){
                        primero = ultimo = nullptr;
                    }else{
                        NodoDCM<T> *segundo = primero->getSiguiente();
                        primero = nullptr; //Elimino referencia
                        primero = segundo;
                        segundo -> setAnterior(primero);    
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
                        NodoDCM<T> *previo = ultimo->getAnterior();
                        ultimo = nullptr;
                        ultimo = previo;
                        ultimo->setSiguiente(primero);
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

                            NodoDCM<T> *iterador = primero;

                            while(indice != 0){
                                iterador = iterador->getSiguiente();
                                indice--;
                            } 

                            if(iterador->getSiguiente() ==  nullptr){
                                eliminarFinal();
                            }else{
                                NodoDCM<T> *previo;
                                NodoDCM<T> *siguiente;

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

                    NodoDCM<T> *nimpreso;
                    nimpreso = primero;

                    cout << "\n... <- ";
                    while( nimpreso != ultimo){

                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();
                        cout<< " <-> ";
                       
                    }
                    cout << ultimo->getValor() << "  -> ..." <<endl;
                }
            }

            void imprimirFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada imprimir"<<endl;
                else{
                    
                        NodoDCM<T> *nimpreso;
                        nimpreso = ultimo;

                        cout << "\n... <- ";
                        while( nimpreso != primero){

                            cout<< nimpreso -> getValor();
                            nimpreso = nimpreso->getAnterior();
                            cout<< " <-> ";
                        
                        }
                        cout << primero->getValor() << "  -> ..." <<endl;
                }
            }

            int buscar(T buscado){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{
                    NodoDCM<T> *iterador = primero;
                    int indice = 0;
                    while( iterador != ultimo){
                        if(iterador->getValor() == buscado) return indice;
                        if(iterador->getSiguiente()->getValor() == buscado) return indice+1;
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
                    ListaDobleC<T> *revertida = new ListaDobleC<T>();
                    NodoDCM<T> *iterador = ultimo;

                    revertida->insertar(iterador->getValor());
                    iterador = iterador->getAnterior();

                    while(iterador != primero){
                        revertida->insertarFinal(iterador->getValor());
                        iterador = iterador->getAnterior();
                    }
                    revertida->insertarFinal(primero->getValor());
                    this->primero = revertida->primero;
                    this->ultimo = revertida->ultimo;
                    free(revertida);
                }
            }

            void imprimir(){
                if (estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{
                    NodoDCM<T> *nimpreso;
                    nimpreso = primero;

                    while( nimpreso != ultimo){
                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();
                    }
                    cout << ultimo->getValor();
                }
            }
    };