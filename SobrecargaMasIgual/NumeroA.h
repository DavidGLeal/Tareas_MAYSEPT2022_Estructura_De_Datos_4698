#include <iostream>

using namespace std;

class NumeroA
{  int a;
   public:
     NumeroA(int);
     void setNumeroA(int);
     int getNumeroA(void);
     void operator += (NumeroA);     
};