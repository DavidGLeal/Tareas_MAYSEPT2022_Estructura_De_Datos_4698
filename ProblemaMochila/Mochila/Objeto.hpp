#include <iostream>
using namespace std;
#pragma once
   
class Objeto{
    private:
        int peso;
        int valor;

    public:

      Objeto(int peso, int valor): peso(peso), valor(valor){

      }
      
      Objeto(){
        Objeto(0,0);
      }

      ~Objeto(){
      }

      int getPeso(){
        return this->peso;
      }

      int getValor(){
        return this->valor;
      }

      void setPeso(int p){
        this->peso = p;
      }

      void setValor(int v){
        this -> valor = v;
      }

      bool operator == (Objeto dos){
        return this->getValor() == dos.getValor() && this->getPeso() == dos.getPeso();
      }
};  