#pragma once
#include "3Celular.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

    Celular::Celular(string m, double p, int s){
        this->marca = m;
        this->precio = p;
        this->stock = s;
    }

    Celular::Celular(){

    }

    Celular::~Celular(){
        free(this);
    }

    //Gests
    string Celular :: getMarca(){
        return marca;
    }

    double Celular ::getPrecio(){
        return precio;
    }

    int Celular ::getStock(){
        return stock;
    }

    int Celular ::getCantidad(){
        return this->cantidad;
    }

    //Sets

    void Celular ::setCantidad(int c){
        this->cantidad = c;
    }

    void Celular ::aumentarCantidad(int c){
        this->cantidad += c;
    }

    void Celular :: setMarca(string _marca){
        marca = _marca;

    }

    void Celular ::setPrecio(double _precio){
        precio = _precio;
    }

    void Celular ::setStock(int _stock){
        stock = _stock;
    }

    bool Celular ::disminuirStock(){
        if(stock > 0){
        --stock; 
        return true;
        }else{
            cout<< "Ya no existe este item en el stock" <<endl;
            return false;
        }
    }

    bool Celular ::disminuirStock(int cantidad){

        if (cantidad == 1){
            return disminuirStock();
        }else if(stock > 0 || stock - cantidad > 0){
            stock = stock - cantidad; 
            return true;
        }else{
            cout<< "No existen tantos items en el stock" <<endl;
            return false;
        }
    }

    string Celular::toString(){
        string t = "Marca = " + this->getMarca() + "\nPrecio = " + to_string(this->getPrecio()) + "\n";
        return t;
    }

    bool Celular::operator ==(Celular c){
        double delta = 0.001;
        
        /*
        cout<< this->getMarca() <<endl;
        cout<< c.getMarca() <<endl;
        cout<< abs(this->getPrecio() - c.getPrecio()) <<endl;
        */

        return this->getMarca() == c.getMarca() && abs(this->getPrecio() - c.getPrecio()) < delta;
    }

    bool Celular::operator ==(Celular* c){
        double delta = 0.001;
        
        /*
        cout<< this->getMarca() <<endl;
        cout<< c.getMarca() <<endl;
        cout<< abs(this->getPrecio() - c.getPrecio()) <<endl;
        */

        return this->getMarca() == c->getMarca() && abs(this->getPrecio() - c->getPrecio()) < delta;
    }

    
    bool Celular::iguales (double num1, double num2, double deltaMax) {
        return (abs(num1 - num2) < deltaMax);
    }