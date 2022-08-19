
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H


#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu.cpp"
#include "OpcionMenu.cpp"
#include "0Vector.cpp"
#include "Rivera.cpp"
#include <iostream>
#include "1IngresoDatos.h"

using namespace std;

int main(int argc, char **argv) {
    Vector v;
    Shell *s = new Shell();
  
    //!Creo objeto menu. Este manejara las opciones
    Menu menu("\t ~~~ Ordenamiento por rango - menu ~~~ \n");
   
    menu.add_option(MenuOption("\t  -> 1. Generar Aleatorio", [&](MenuOptionArguments args) {
        
        v.vaciar();
        s->generarRandom(v, 100);
        v.imprimir(v);

    }));


    menu.add_option(MenuOption("\t  -> 2. Ordenar por rango", [&](MenuOptionArguments args) {

        if(v.empty()){
            cout << "Genere datos primero" <<endl;
            system("pause");
        }else{
            IngresoDatos *i = new IngresoDatos();
            cout << "\n";
            int num = i->funcionPrincipalEnteros("Ingrese el rango: ");

            if(num <= 0 || num > 100){
                cout << " ~~ Debe ingresar un numero valido. Mayor que 0 y menor que 101 ~~ " <<endl;
            }else{
                s->rango(v,num);
            }
        }

    }));



    //!Funcion salida del menu
    menu.add_option(MenuOption("\t  -> Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

