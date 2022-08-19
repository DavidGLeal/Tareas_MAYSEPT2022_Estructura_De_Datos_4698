#ifndef T2CONVERSIONFLOAT_H
#define T2CONVERSIONFLOAT_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "t2Conversion.h"


class ConversionFloat: public Conversion{
    public:
        ConversionFloat();
        bool verificar(char c);
        float numFloat(char* dato);
        
};

#endif 