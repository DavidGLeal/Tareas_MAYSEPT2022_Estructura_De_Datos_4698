#include "Cadena.h"

Cadena::Cadena(char *c)
{    strcpy(cad,c);
}

char *Cadena::DameCadena(void)
{    return cad; 
}

void Cadena::operator + (Cadena C)
{    strcat(cad, C.DameCadena()); 
}