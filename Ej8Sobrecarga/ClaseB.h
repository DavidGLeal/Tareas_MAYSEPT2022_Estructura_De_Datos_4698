#include "ClaseA.cpp"

class B //agregado
{    int b;
     int cant;
     A m[20];
   public:
     B(void);
     void DefineB(int);
     int DameB(void);
     int DameCant(void);
     void Ingresa(int);
     int operator[](int);
};