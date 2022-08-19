#include "Mochila.hpp"
#include <iostream>
using namespace std;

int main(){
    
    Objeto o1(1,5);
    Objeto o2(2,3);
    Objeto o3(4,5);
    Objeto o4(2,8);
    Objeto o5(5,2);

    Objeto* arreglo = new Objeto[5]{o1,o2,o3,o4,o5};

    Mochila m(10, 5, arreglo);

    m.obtenerBeneficio();

    return 0;
}