#include "NumeroA.h"

NumeroA::NumeroA(int x)
{    a = x; 
}

void NumeroA::setNumeroA(int x)
{    this -> a = x; 
}

int NumeroA::getNumeroA(void)
{    return a; 
}

void NumeroA::operator += (NumeroA num)
{    this -> setNumeroA(num.getNumeroA()*(num.getNumeroA()-1)); 
}


