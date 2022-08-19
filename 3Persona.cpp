#pragma once
#include "3Persona.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

    Persona::Persona(string n, string m, double p, long ced){
        this->nombre = n;
        this->presupuesto = p;
        this->apellido = m;
        this ->cedula = ced;
    }

    Persona::~Persona(){
        free(this);
    }


    Persona::Persona(){
    }

    void Persona::comprarCelular(Celular* celu){

        if(verificarCelular(celu)){
            //out<< "1 if" <<endl;
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                if(this->presupuesto - celu->getPrecio() > 0){
                    //cout<< "3 if" <<endl;
                    if(celu->disminuirStock()){
                        //cout<< "4 if" <<endl;
                        this->presupuesto -= celu->getPrecio();
                        celu->aumentarCantidad(1);
                        this->comprados->insertarFinal(celu);
                        cout<< "\n-- Compra realizada con exito --" <<endl;
                    }else{
                        //cout<< "3 if" <<endl;
                        celu->disminuirStock(); 
                    }
                }else{
                    //cout<< "5 if" <<endl;
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                } 

            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            } 

        }else{

            if(disminuirPresupuesto()){
                if(this->presupuesto - celu->getPrecio() > 0){

                    if(celu->disminuirStock()){
                        this->presupuesto -= celu->getPrecio();
                        NodoDC<Celular*> *it =comprados->obtenerUltimo();
                        int cont = 0;
                        while(cont < comprados->obtenerLongitud()){
                        if(*(it -> getValor()) == *celu){
                            (it->getValor())->aumentarCantidad(1);
                        }
                        it = it->getAnterior();
                        cont++;
                        }
                    }else{
                        celu->disminuirStock();                
                    }    
                }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                }
            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            }   
        }
    }
    
    void Persona::comprarCelular(Celular* celu, int cantidad){

        if(verificarCelular(celu)){
            if(disminuirPresupuesto()){
                if(this->presupuesto - celu->getPrecio()*cantidad > 0 ){
                    if(celu->disminuirStock(cantidad)){
                        this->presupuesto -= celu->getPrecio()*cantidad;
                        celu->aumentarCantidad(cantidad);
                        this->comprados->insertarFinal(celu);
                    }else{
                    celu->disminuirStock(cantidad);                
                    }    
                }else{
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl; 
                }  
            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            }
        }else{

                if(disminuirPresupuesto()){
                    if(this->presupuesto - celu->getPrecio()*cantidad > 0){
                        if(celu->disminuirStock(cantidad)){
                            this->presupuesto -= celu->getPrecio()*cantidad;
                        
                            NodoDC<Celular*> *it =comprados->obtenerUltimo();

                            int cont = 0;
                            while(cont < comprados->obtenerLongitud()){
                                if(*(it -> getValor()) == *celu){
                                    (it->getValor())->aumentarCantidad(cantidad);
                                }
                                it = it->getAnterior();
                                cont++;
                            }
                        }else{
                        celu->disminuirStock(cantidad);  
                        }
                    }else{
                        cout<< "No posee el suficiente dinero para comprar esto" <<endl;                
                    }
                }else{
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                }
                    
        }    
    }

    
    bool Persona::verificarCelular(Celular* celu){
        NodoDC<Celular*> *it =comprados->obtenerUltimo();
        int cont = 0;
        while(cont < comprados->obtenerLongitud()){ 
            if(*(it -> getValor()) == *celu){
                return false;
            }
            cont++;
            it = it->getAnterior();
        }

        return true;
    }

    bool Persona::disminuirPresupuesto(){
        if(this->presupuesto > 0){
            return true;
        }
        else return false;
    }

    void Persona::verComprados(){

        if (comprados->estaVacio()) cout<< " ningun celular todavia"<<endl;
            else{
                    
                NodoDC<Celular*> *nimpreso;
                nimpreso = comprados->obtenerUltimo();

                while( nimpreso != comprados->obtenerPrimero()){

                    cout<< nimpreso -> toString()<< " y ha comprado "<< (nimpreso->getValor())->getCantidad() << " items de este tipo" <<endl;
                    nimpreso = nimpreso->getAnterior();
                
                }
                cout << (comprados->obtenerPrimero())->toString()<< " y ha comprado "<< ((comprados->obtenerPrimero())->getValor())->getCantidad() << " items de este tipo" <<endl;
            }
    }

    //Metodos
    //Gests
    string Persona::getNombre(){
        return nombre;

    }
    double Persona ::getPresupuesto(){
        return presupuesto;
    }

    ListaDobleC<Celular*>*  Persona ::getComprados(){
        return comprados;
    }

    //Setter
    void Persona ::setNombre(string _nombre){
        nombre = _nombre;

    }

    void Persona ::setPresupuesto(double _presupuesto){
        presupuesto = _presupuesto;

    }
    void Persona :: setComprados(ListaDobleC<Celular*>*list){
        comprados = list;

    }

    string Persona::toString(){
        string s =  this->getNombre() + ", tiene un presupuesto de " + to_string(this->getPresupuesto()) + " y de cedula " + to_string(this->getCedula()) + "\nAdemas el correo es: " + this->getCorreo();
        return s;
    }

    void Persona::generarCorreo(){
        int l = this->getNombre().length();
        char *n = new char[l+1];

        strcpy(n, this->getNombre().c_str());

        string correo = n[0] + this->getApellido() + "@evaluacion.com";

        this->setCorreo(correo);
    }

    void Persona::generarCorreoRepetido(){

        int l = this->getNombre().length();
        char *n = new char[l+1];

        strcpy(n, this->getNombre().c_str());

        string correo = n[0] + this->getApellido() + "1@evaluacion.com";

        this->setCorreo(correo);
    }
