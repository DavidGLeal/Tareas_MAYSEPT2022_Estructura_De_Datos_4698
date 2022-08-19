#include <iostream>
#include <iomanip>
using namespace std;

class Vector
{    float x;
     float y;
   public:
     Vector(float cx=0, float cy=0);
     void DefineX(float);
     void DefineY(float);
     float DameX(void);
     float DameY(void);
     float operator * (Vector);
};