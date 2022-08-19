/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  9 DE AGOSTO DE 2022
* FECHA DE Entrega: 10 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu/Menu.cpp"
#include "Menu/OpcionMenu.cpp"
#include "Pascal/Pascal.hpp"
#include "IngresoDatos/IngresoDatos.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    
    Pascal p;
    
    Menu menu("\n \t ~~ TRIANGULO DE PASCAL ~~ ");
   

    //!Submenus
    menu.add_option(MenuOption(" \t ~~ Empezar", [&](MenuOptionArguments args) {
        system("CLS"); 
        IngresoDatos i;
        int ingresado{-1};

        while(ingresado == -1){
            ingresado = i.funcionPrincipalEnteros("Ingrese el nivel del triangulo: ");
        }

        Pascal p1(ingresado);
        p = p1;

        system("CLS");
        Menu menuInterno("Submenu");

        
        menuInterno.add_option(MenuOption("\t ~ 1. Imprimir Normal", [&](MenuOptionArguments args) {
            cout << endl;
            p.imprimir();
        }));

        menuInterno.add_option(MenuOption("\t ~ 2. Imprimir invertido", [&](MenuOptionArguments args) {
            cout<<endl;
            p.imprimirInv();
        }));
        

        menuInterno.add_option(MenuOption("\t ~ Regresar al menu principal", [&](MenuOptionArguments args) {
            menuInterno.stop();
        }, false));

        menuInterno.display();

    }));

    

    //!Funcion salida del menu
    menu.add_option(MenuOption("\t ~~ Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

