
#include <iostream>
using namespace std;
#include "Pila.h"

int main(){

    Pila<int> *pila = new Pila<int>();
    pila->apilar(1);
    pila->apilar(2);
    pila->apilar(3);
    pila->apilar(4);
    pila->apilar(5);
    pila->apilar(6);
    
    pila->mostrar();

    cout << "\n";
    cout << pila->sumaPares() <<endl;

    return 0;
}