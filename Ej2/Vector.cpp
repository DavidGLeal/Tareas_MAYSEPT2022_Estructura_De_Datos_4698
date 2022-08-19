#include"Vector.h"

Vector::Vector(float cx, float cy)
{    x=cx; y=cy;
}

void Vector::DefineX(float cx)
{    x=cx; 
}

void Vector::DefineY(float cy)
{    y=cy; 
}

float Vector::DameX(void)
{    return x; 
}

float Vector::DameY(void)
{    return y; 
}

float Vector::operator * (Vector V)
{    return (x*V.DameX() + y*V.DameY()); 
}