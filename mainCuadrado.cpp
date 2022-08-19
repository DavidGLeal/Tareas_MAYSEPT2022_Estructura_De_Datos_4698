/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
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
#include "CuadradoMagico/CuadradoMagico.hpp"
#include "ValidacionDatos/IngresoDatos.h"

using namespace std;

int main(int argc, char **argv) {
   
    Menu menu("\n\n \t ~~ Cuadrado magico");
   
    menu.add_option(MenuOption("\t ~ Comenzar", [&](MenuOptionArguments args) {

        system("CLS"); 
        IngresoDatos i;
        int ingresado{-1};

        while(ingresado == -1){
            ingresado = i.funcionPrincipalEnteros("Ingrese el valor con el que desea calcular la constante magica.\n Si deja el apartado vacio, se asumira una constante para un cubo tradicional magico 3x3.\n");

            if(ingresado == -10101010){
                ingresado = 1;
            }
        }

        CuadradoMagico cuadrado(ingresado);
        system("pause");
        system("CLS");
        Menu menuInterno("\n\t ~Metodos~");

        
        menuInterno.add_option(MenuOption("\t ~ 1er Metodo ~", [&](MenuOptionArguments args) {
            system("CLS");
            cout << "\n Este metodo, que consiste en varias iteraciones, resolvera un cuadrado magico clasico, 3x3, con numeros del 1 al 9 sumando 15." <<endl;
            cout << "\n Resultado del metodo I: " <<endl;
            cuadrado.metodoI();
      
        }));

        menuInterno.add_option(MenuOption("\t ~ 2do Metodo ~", [&](MenuOptionArguments args) {

            system("CLS");
            cout << "\nEste metodo trabaja con artificios matematicos como la potencia. Y se adapta al numero magico que brinde el usuario." <<endl;
            cout << "\n Resultado del metodo II: " <<endl;
            cuadrado.metodoII();
      
        }));
        
        menuInterno.add_option(MenuOption("\t ~ 3er Metodo ~", [&](MenuOptionArguments args) {
            system("CLS");
            cout << "\n Este algoritmo hace uso del espacio de un arreglo mucho mas grande que su capacidad. Y se adapta al numero magico nuevo brindado por el usuario." <<endl;
            cout << "\n Resultado del metodo III: " <<endl;
            cuadrado.metodoIII();
    
        }));

        menuInterno.add_option(MenuOption("\t ~ Regresar al inicio ~", [&](MenuOptionArguments args) {
            menuInterno.stop();
        }, false));

        menuInterno.display();

    }));


    //!Funcion salida del menu
    menu.add_option(MenuOption("\t ~ Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

