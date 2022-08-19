#ifndef T3INGRESODATOS_H
#define T3INGRESODATOS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdexcept>

#include "t3ConversionInt.h"
#include "t3ConversionFloat.h"
using namespace std;

class IngresoDatos{
    private:
        ConversionInt converInt;
        ConversionFloat converFloat;
        char det;
    public:
        IngresoDatos();  


        //Metodo principal
        char *agregoChars(char *dato);

        //Submetodos
        char getDet();

        //Metodos de retorno
        int devolverInt(char *dato);
        float devolverFloat(char *dato);
};

#endif  