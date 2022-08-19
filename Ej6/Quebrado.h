#ifndef QUEBRADO_H
#define QUEBRADO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Quebrado
{   
    private:
        int numerador;
        int denominador;

   public:
        Quebrado (int, int);
        Quebrado ();
        void DefineNum (int);
        void DefineDen (int);
        int DameNum (void);
        int DameDen (void);
        Quebrado operator+ (Quebrado &);
        // la referencia es sólo por eficiencia
        void imprimirObjeto();
};

#endif 