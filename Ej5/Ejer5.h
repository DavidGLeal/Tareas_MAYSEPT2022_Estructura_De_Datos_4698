#ifndef EJER5_H
#define EJER5_H
#include<iostream>
#include<iomanip>

using namespace std;
class A
{    float x;
  	 public:
     A(float cx=0);
     void DefineX(float);
     float DameX(void);
     A operator ++ (void); // como prefijo
     A operator ++ (int);  // como sufijo
                           // el par�metro int es obligatorio
};

#endif
