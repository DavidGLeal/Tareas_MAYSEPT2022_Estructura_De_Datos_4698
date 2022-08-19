#include "ClaseB.h"

B::B(void)
{    cant = 0;
}

void B::DefineB(int x)
{    this -> b = x; 
}

int B::DameB(void)
{    return b; 
}

int B::DameCant(void)
{    return cant; 
}

void B::Ingresa(int x)
{    m[cant++].DefineA(x); 
}

int B::operator[](int i)
{    return m[i].DameA(); 
}
