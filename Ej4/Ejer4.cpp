#include "Ejer4.h"

Complejo::Complejo(float r, float i)
{    real=r; imag=i; 
}

void Complejo::DefineR(float r)
{    real=r; 
}

void Complejo::DefineI(float i)
{    imag=i; 
}

float Complejo::DameR(void)
{    return real; 
}

float Complejo::DameI(void)
{    return imag; 
}

Complejo Complejo::operator + (Complejo C)
{    return Complejo(real+C.DameR() , imag+C.DameI());
}

Complejo Complejo::operator - (Complejo C)
{    return Complejo(real-C.DameR() , imag-C.DameI());
}
