#include "1Pila.hpp"
#include <iostream>
#include "Proceso.cpp"
#include <regex>
using namespace std;
#include <cstring>


int main(){


    while(true){

        Proceso *p = new Proceso();
        p->recibirExpresion();
        p->setPostfija(p->convertirPostfija(p->getInfija()));
        p->imprimirNotacion(p->getPostfija());
        p->setPrefija(p->convertirPrefija(p->getInfija()));
        p->imprimirNotacion(p->getPrefija());
        cout << "\n";
        p->resolverPost(p->getPostfija());
        p->resolverPre(p->getPrefija());

        delete p;
    }
   
 
    return 0;
}
