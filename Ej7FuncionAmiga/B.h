#ifndef B_H
#define B_H

#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "A.h"
using namespace std;

class B
{    int b;
   public:
     void defineB(int);
     int dameB(void);
     int P(A OA);
};

#endif 