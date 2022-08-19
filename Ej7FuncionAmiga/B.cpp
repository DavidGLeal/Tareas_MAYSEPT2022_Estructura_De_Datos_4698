#include"A.h"
#include"B.h"

void B::defineB(int x)
{    b = x; 
}

int B::dameB(void)
{    return b; 
}

int B::P(A OA)
{    B Ob;
     Ob.defineB(2);
     return OA.dameA()*Ob.dameB(); 
}
