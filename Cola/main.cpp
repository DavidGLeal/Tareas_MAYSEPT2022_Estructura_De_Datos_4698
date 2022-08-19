
#include <iostream>
using namespace std;
#include "Cola.hpp"

int main(){

    Cola<int> *cola = new Cola<int>();

    cola->pushLast(1);
    cola->pushLast(2);
    cola->pushLast(3);
    cola->pushLast(4);

    cola->imprimir();

    cout <<endl;
    cout << cola->poll() <<endl;
    cout << cola->peek() <<endl;
    cout << cola->poll() <<endl;
    cout << cola->poll() <<endl;
    cout << cola->poll() <<endl;
    
    
    
    cola->imprimir();

    cout<< cola->estaVacia() <<endl;

    return 0;
}