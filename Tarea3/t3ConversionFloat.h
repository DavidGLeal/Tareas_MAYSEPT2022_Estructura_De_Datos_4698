#ifndef T3CONVERSIONFLOAT_H
#define T3CONVERSIONFLOAT_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "t3Conversion.h"


class ConversionFloat: public Conversion{
    public:
        ConversionFloat();
        bool verificar(char c);
        float numFloat(char* dato);
        
};

#endif 