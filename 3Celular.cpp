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
#include "3Celular.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

    /**
     * @param m
     * @param p
     * @param s
     */
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

    /**
     * @return getMarca
     */
    //Gests
    string Celular :: getMarca(){
        return marca;
    }


    /**
     * @return getPrecio
     */
    double Celular ::getPrecio(){
        return precio;
    }

    /**
     * @return getStock
     */
    int Celular ::getStock(){
        return stock;
    }



    //Sets

    /**
     * @param 
     * @return aumentarStock
     */
    void Celular ::aumentarStock(int c){
        this->stock += c;
    }

    /**
     * @param 
     * @return setMarca
     */
    void Celular :: setMarca(string _marca){
        marca = _marca;

    }

    /**
     * @param 
     * @return setPrecio
     */
    void Celular ::setPrecio(double _precio){
        precio = _precio;
    }

    /**
     * @param 
     * @return setPrecio
     */
    void Celular ::setStock(int _stock){
        stock = _stock;
    }

    /**
     * @param 
     * @return aumentarStock
     */
    bool Celular::disminuirStock(){
        
        if(stock > 0){
            --stock; 
            return true;
        }else{
            cout<< "Ya no existe este item en el stock" <<endl;
            return false;
        }
    }


    /**
     * @param 
     * @return disminuirStock
     */
    bool Celular::disminuirStock(int cantidad){

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


    /**
     * @param 
     * @return disminuirStock
     */
    string Celular::toString(){
        string t = "Marca = " + this->getMarca() + "\nPrecio = " + to_string(this->getPrecio()) + "\n";
        return t;
    }

    /**
     * @param 
     * @return operator
     */
    bool Celular::operator ==(Celular &c){
        double delta = 0.01;
        
        
        //cout<< this->getMarca() <<endl;
        //cout<< c.getMarca() <<endl;
        //cout<< abs(this->getPrecio() - c.getPrecio()) <<endl;
        

        return this->getMarca() == c.getMarca() && abs(this->getPrecio() - c.getPrecio()) < delta;
    }
    
    /*
    bool Celular::operator ==(Celular* c){
        double delta = 0.01;
        
        
        cout<< this->getMarca() <<endl;
        cout<< c.getMarca() <<endl;
        cout<< abs(this->getPrecio() - c.getPrecio()) <<endl;
        

        return this->getMarca() == c->getMarca() && abs(this->getPrecio() - c->getPrecio()) < delta;
    }
    */
    

    /**
     * @param num1
     * @param num2
     * @param deltaMax
     * @return iguales
     */
    bool Celular::iguales (double num1, double num2, double deltaMax) {
        return (abs(num1 - num2) < deltaMax);
    }