#pragma once
#include "3Tienda.h"
#include "3Celular.cpp"
#include "1NodoDC.hpp"

    Tienda::Tienda(){

    }

    Tienda::~Tienda(){
        free(this);
    }

    bool Tienda::estaVacio(){
        if(this->stock == nullptr){
            return true;
        }

        else return false;
    }

    void Tienda::setStock( Stock * s){
        this->stock = s;
    }

    Stock*  Tienda::getStock(){
        return this->stock;
    }

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::recomendarCelulares(Persona* persona){
       //cout<<persona->getPresupuesto() <<endl;
       return celularesPorPresupuestoMenor(persona->getPresupuesto());
    } //Recomendar automaticamente a la persona un celular por presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMenor(double p){

        this->stock->ordenarPorPrecio();
        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerPrimero();
        int cont = 0;

        if (p > (stock->getCelulares()->obtenerUltimo()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<<"Entro al while grande"<<endl;
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;
            if((it->getValor())->getPrecio() > p){

               it = it->getAnterior(); 
               while(cont != 0){
                    //cout<<"Entro al while peque"<<endl;
                    //cout<< cont <<endl;
                    presupuesto->insertarFinal(it->getValor());
                    it = it->getAnterior();
                    cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }else{
            it = it->getSiguiente();
            cont++;
            }
        }

        if(presupuesto->obtenerPrimero() == nullptr){
            cout << "No se encontro el criterio" <<endl;
        }

        //cout<<"Llegue al final"<<endl;
        return presupuesto;
    } //Devolver los celulares menores o iguales que el presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMayor(double p){

        this->stock->ordenarPorPrecio();
        //this->getStock()->getCelulares()->imprimirObjetoInicio();
        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerUltimo();
        int cont = 0;

        if (p < (stock->getCelulares()->obtenerPrimero()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                //cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;

            if((it->getValor())->getPrecio() < p){

               it = it->getSiguiente();
               while(cont != 0){ 
                   //cout<< cont <<endl;
                   presupuesto->insertarFinal(it->getValor());
                   it = it->getSiguiente();
                   cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }

            it = it->getAnterior();
            cont++;
        }
        
        
        if(presupuesto == nullptr){
            cout << "No se encontro el criterio" <<endl;
        }

        return presupuesto;
    } //Devolver celulares mayores o iguales que el presupuesto

    ListaDobleC<Persona*>* Tienda::personasPorPresupuestoIgual(double valor) {

		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
        Celular *c = new Celular();
		int cont = 0;
		
		while (cont < stock->getPersonas()->obtenerLongitud()) {

			if (c->iguales(it->getValor()->getPresupuesto(), valor, 1e-3)){
				l->insertarFinal(it->getValor());
                cout<<"Entro al if"<<endl;
                cont = stock->getPersonas()->obtenerLongitud();
            }   
				
			it = it->getAnterior();
			cont++;
		}
		
        cout<<"Salgo de la funcion"<<endl;
		return l;
	}
	
	ListaDobleC<Persona*>* Tienda::personasPorNombreIgual(string valor) {

		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if (it->getValor()->getNombre() == valor)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
	}

    ListaDobleC<Celular*>* Tienda::celularesPorPrecioIgual(double pres){
        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getCelulares()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if (it->getValor()->getPrecio() == pres)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }

	ListaDobleC<Celular*>* Tienda::celularesPorMarcaIgual(string nombre){

        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << nombre <<endl;

		while (cont < stock->getCelulares()->obtenerLongitud()) {
            cout<< it->getValor()->getMarca() <<endl;

			if (it->getValor()->getMarca() == nombre)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}

        /*
        if(l->obtenerPrimero() == nullptr){
            cout<< "No se encontro la instancia"<<endl;
        }
        */
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }

   