#ifndef T2CONVERSIONINT_H
#define T2CONVERSIONINT_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "t2Conversion.h"

using namespace std;

class ConversionInt: public Conversion{
    public:
        ConversionInt();
        bool verificar(char c);
        int numInt(char* dato);
};


#endif 