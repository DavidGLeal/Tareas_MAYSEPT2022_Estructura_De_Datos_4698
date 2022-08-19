#pragma once
#include <iostream>
#include <cmath>
using namespace std;
#include "0Vector.cpp"

   
class Shell{
    private:

    public:

        Shell(){

        }
        ~Shell(){
            
        }
        void ordenarShell(Vector *v);
        Vector* dividir(Vector &v, int comienzo, int ran);
        void generarRandom(Vector &v, int tam);
        void rango(Vector &v, int ran);
};