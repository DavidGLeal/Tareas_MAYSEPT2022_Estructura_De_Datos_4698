#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;
class Cadena
{    char cad[40];
   public:
     Cadena(char *);
     char * DameCadena(void);
     void operator + (Cadena);
};