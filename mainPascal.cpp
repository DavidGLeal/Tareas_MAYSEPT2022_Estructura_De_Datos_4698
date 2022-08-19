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
   
    
    Menu menu("\n \t ~~ TRIANGULO DE PASCAL ~~ ");
   

    //!Submenus
    menu.add_option(MenuOption(" \t ~~ Empezar", [&](MenuOptionArguments args) {
        system("CLS"); 
        IngresoDatos i;
        int ingresado{-1};

        while(ingresado == -1){
            ingresado = i.funcionPrincipalEnteros("Ingrese el nivel del triangulo: ");
        }

        Pascal p(ingresado);
        cout<<endl;
        p.imprimirInv();

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

