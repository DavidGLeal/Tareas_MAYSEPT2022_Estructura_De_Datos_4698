#pragma once
#include <iostream>
using namespace std;

   
class Resultado{
    
    private:

        int resultado;

    public:

        Resultado(int resultado) : resultado{resultado}{}

        ~Resultado(){}

        int getPosBusqueda(){
            return resultado;
        }

        int getPosInsercion(){
            return (-this->resultado - 1);
        }

        bool datoEncontrado(){
            return (this->resultado >= 0);
        }

};