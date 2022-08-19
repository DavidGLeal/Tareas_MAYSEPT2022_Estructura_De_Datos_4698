#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu/Menu.cpp"
#include "Menu/OpcionMenu.cpp"
#include "LecturaDatos/IngresoDatos.hpp"
#include "Cambio/Cambio.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
   
    Menu menu("\n\n\t ~~ Canjeo de monedas");
    Cambio c;

    menu.add_option(MenuOption("\t ~~ 1. Realizar cambio", [&](MenuOptionArguments args) {
       
       IngresoDatos i;
       bool cont{true};
       float valor;

       while(cont){

            cout << "\n\t - Ingrese la cantidad de dinero que desea cambiar: ";
            valor = i.leerDinero();

            if(i.vacio()){
                cout << "\n\t ~~ Por favor ingrese una cantidad ~~"<<endl;
                system("pause");
                system("CLS");
            }else if(i.invalido()){
                cout << "\n\t ~~ Por favor ingrese una cantidad valida. No signos negativos y no letras ~~"<<endl;
                system("pause");
                system("CLS");
            }else{
                Cambio aux(valor);
                c=aux;
                cont = false;
            }

       } 

        cout << endl;
        c.hacerCambio();

    }));


    menu.add_option(MenuOption("\t ~~ 2. Ver registro de billetes y monedas", [&](MenuOptionArguments args) {
        c.imprimirCambios();
    }));


    //!Funcion salida del menu
    menu.add_option(MenuOption("\t ~~ 3. Salir", [&](MenuOptionArguments args) {
        cout << "\n \t ~~ Gracias por usar el programa!" <<endl;
        c.guardarArchivo();
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

