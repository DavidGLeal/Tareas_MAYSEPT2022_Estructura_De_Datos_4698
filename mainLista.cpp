#include "Lista.cpp"
#include "IngresoDatos.cpp"
#include <iostream>
using namespace std;

int main(){

    ListaEnlazada *l = new ListaEnlazada();
    IngresoDatos *i = new IngresoDatos();
    IngresoDatos *m = new IngresoDatos();
    int cont = 0;

    while (cont != 2){
        cont = 0;
        cout<< "Que desea realizar?\n";
        cout<< "1) Agregar datos\n";
        cout<< "2) Parar y ver la impresion\n";
        cont = m -> funcionPrincipal();

        cout<< "\n" << cont << " CONTADOR"<<endl;
        if (cont == 1){
            l ->agregarFinal(i ->funcionPrincipal("\n Ingrese sus datos: "));
            system("CLS"); //Limpio pantalla
        }else if (cont ==2){
            cout<<"\n Sus datos son \n";
        }else{
            cout<<"Ingrese un numero valido\n";
        }
    }

    l -> imprimirCabeza();

    return 0;
}