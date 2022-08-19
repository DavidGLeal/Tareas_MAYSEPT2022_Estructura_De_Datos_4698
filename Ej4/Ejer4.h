#ifndef EJER4_H
#define EJER4_H
#include<iostream>
#include<iomanip>
using namespace std;
class Complejo
{    float real;
     float imag;
   public:
     Complejo(float r=0, float i=0);
     void DefineR(float);
     void DefineI(float);
     float DameR(void);
     float DameI(void);
     Complejo operator + (Complejo);
     Complejo operator - (Complejo);
};

#endif