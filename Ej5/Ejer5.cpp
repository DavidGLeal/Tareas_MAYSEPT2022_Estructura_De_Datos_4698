#include "Ejer5.h"

A::A(float cx)
{    
	x=cx; 
 }

float A::DameX(void)
{    
	return x; 
 }

A A::operator ++ (void)
{   
 x=x*x;
     return *this;
 }

A A::operator ++ (int)
{    A aux=*this;
     x=x*x;
     return aux;
 }
