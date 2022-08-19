#include <iostream>
#include "ListaD.hpp"
using namespace std;

int main(){

    ListaDoble<int> *lista = new ListaDoble<int>();

    lista->insertar(10);

    lista->insertarInicio(5);
    lista->insertarInicio(0);
    lista->insertarFinal(15);
    lista->insertarFinal(20);
    lista->insertar(2, 4);

    lista->imprimirInicio();
    lista->revertir();
    lista->imprimirInicio();
    
    return 0;
}