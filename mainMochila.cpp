#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "ProblemaMochila/Lectura Datos/IngresoDatos.hpp"
#include "ProblemaMochila/Menu/Menu.cpp"
#include "ProblemaMochila/Menu/OpcionMenu.cpp"
#include "ProblemaMochila/Mochila/Mochila.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
   
    Menu menu("\n\n\t ~~ Problema de la mochila");
    Mochila m;

    menu.add_option(MenuOption("\t ~~ 1. Empezar", [&](MenuOptionArguments args) {
       
        IngresoDatos i;
        cout << "\n\t - Ingrese la cantidad de objetos que desea ingresar: ";
        int cant = i.ingresarEnteroSinSigno();
        Objeto* arreglo = new Objeto[cant];
        int cont{0};

        while(cont != cant){

            if(i.vacio()){
                cout << "\n\t ~~ Por favor ingrese una cantidad ~~"<<endl;
                system("pause");
                system("CLS");
            }else if(i.invalido()){
                cout << "\n\t ~~ Por favor ingrese una cantidad valida. No signos negativos y no letras ~~"<<endl;
                system("pause");
                system("CLS");
            }else{

                cout << "\n\t - Ingrese el peso del objeto " << cont + 1 << ": ";
                int peso = i.ingresarEnteroSinSigno();
                bool verf{true};

                while(verf){
                
                    if(i.vacio()){
                        cout << "\n\t ~~ Por favor ingrese una cantidad ~~"<<endl;
                        system("pause");
                        system("CLS");
                    }else if(i.invalido()){
                        cout << "\n\t ~~ Por favor ingrese una cantidad valida. No signos negativos y no letras ~~"<<endl;
                        system("pause");
                        system("CLS");
                    }else{

                        cout << "\n\t - Ingrese el valor del objeto " << cont + 1 << ": ";
                        int valor = i.ingresarEnteroSinSigno();
                        bool verV{true};

                        while(verV){
                
                            if(i.vacio()){
                                cout << "\n\t ~~ Por favor ingrese una cantidad ~~"<<endl;
                                system("pause");
                                system("CLS");
                            }else if(i.invalido()){
                                cout << "\n\t ~~ Por favor ingrese una cantidad valida. No signos negativos y no letras ~~"<<endl;
                                system("pause");
                                system("CLS");
                            }else{

                                Objeto o(peso,valor);
                                arreglo[cont] = o;
                                verV = false;
                                verf = false;
                                cont++;

                            }
                        }
                    }
                }
            }
        }

        cout << "\n\t - Ingrese el peso de la mochila: ";
        int pesoM = i.ingresarEnteroSinSigno();
        bool v{true};

        while(v){

            if(i.vacio()){
                cout << "\n\t ~~ Por favor ingrese una cantidad ~~"<<endl;
                system("pause");
                system("CLS");
            }else if(i.invalido()){
                cout << "\n\t ~~ Por favor ingrese una cantidad valida. No signos negativos y no letras ~~"<<endl;
                system("pause");
                system("CLS");
            }else{
                Mochila mochila(pesoM, cant, arreglo);
                m = mochila;
            }
        }

        m.obtenerBeneficio();

    }));


    //!Funcion salida del menu
    menu.add_option(MenuOption("\t ~~ 3. Salir", [&](MenuOptionArguments args) {
        cout << "\n \t ~~ Gracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}
