/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  13 DE AGOSTO DE 2022
* FECHA DE Entrega: 14 DE AGOSTO DE 2022
* Version: final
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <iostream>
using namespace std;
#pragma once
   
class Moneda{
    private:
        float valor;
        int cantidad{0};

    public:
      Moneda(float valor, int cantidad): valor(valor), cantidad(cantidad){

      }
      
      Moneda(){
      }

      ~Moneda(){
      }

      int getCantidad(){
        return this->cantidad;
      }

      void disminuirCantidad(){
        this->cantidad--;
      }

      void reiniciarCantidad(){
        this->cantidad = 0;
      }

      void disminuirCantidad(int v){
        this->cantidad = cantidad - v;
      }

      void aumentarCantidad(){
        this->cantidad++;
      }

      void aumentarCantidad(int v){
        this->cantidad = cantidad + v;
      }

      float getValor(){
        return this->valor;
      }

      bool estaAgotado(){
        return this->cantidad == 0;
      }

      bool operator == (Moneda dos){
        return this->getValor() == dos.getValor();
      }

};