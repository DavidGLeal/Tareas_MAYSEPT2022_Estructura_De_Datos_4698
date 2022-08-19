#pragma once
#include "Nodo.h"
template <typename T>

class Pila{
private:
	Nodo<T>* primero= nullptr;
	Nodo<T>* siguiente= nullptr;
	int longitud=0;

public:
	Pila(){
		longitud=0;
	}
	~Pila(){
		free(this);
	}
	void apilar(T v) {
    	Nodo<T> *nuevo = new Nodo<T>(v);

    	if (primero == nullptr) {
        	primero = siguiente = nuevo;
			
    	}else {    	
			nuevo->setNodo(siguiente);
			siguiente=nuevo;
		}

		longitud++;
	}

	void mostrar(){
    	Nodo<T> * tmp=this->siguiente;
    	while (tmp !=nullptr){
        std::cout << tmp->getValor()<<" ";
        tmp = tmp->getNodo();
    	}
	}	

	void desapilar() {
		Nodo<T> * tmp;
		if(primero == nullptr){
			cout<<"\n Pila Vacia"<<endl;
		}else if(primero ==siguiente){
			Nodo<T>  *aux_borrar=siguiente->getNodo();
			cout<<"\n Desapilando: "<<aux_borrar->getValor()<<endl;
			primero = siguiente=nullptr;
			aux_borrar->~Nodo();
		}else{
    		Nodo<T>  *aux_borrar=siguiente;
			cout<<"\n Desapilando: "<<aux_borrar->getValor()<<endl;
			siguiente=aux_borrar->getNodo();
			aux_borrar->~Nodo();
        }
		longitud--;
    }

	int sumaPares(){
		Nodo<T> *it = primero;
		int suma = 0;
		while(it!=nullptr){
			if((it->getValor()%2) == 0){
				suma += it->getValor();
			}

			it = it->getNodo();
		}

		return suma;
	}
};	
	


