
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H


#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu.cpp"
#include "OpcionMenu.cpp"
#include "ListaD.hpp"
#include "ZIngresoDatos.hpp"

#include <iostream>



using namespace std;

int main(int argc, char **argv) {
   
    //!Creo objeto menu. Este manejara las opciones
    Menu menu("Listas Dobles");
    ListaDoble<int> *lista = new ListaDoble<int>();
   
    menu.add_option(MenuOption("Agregar Datos", [&](MenuOptionArguments args) {
       
        system("CLS");
        Menu menuInternoA("Agregar datos");

        if(lista->estaVacio()){
                menuInternoA.add_option(MenuOption("Agregar", [&](MenuOptionArguments args) {

                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
               
                    lista -> insertar(i -> funcionPrincipalEnteros("Ingrese un valor: "));
                    lista->imprimirInicio();
                    cout << "\n[elemento agregado]" <<endl;
                    menuInternoA.stop();
                }, false));

        }else{
            
            do{

                menuInternoA.add_option(MenuOption("Agregar al inicio", [&](MenuOptionArguments args) {
                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();

                    lista -> insertarInicio(i -> funcionPrincipalEnteros("Ingrese un valor: "));
                    lista->imprimirInicio();
                    cout << "\n[elemento agregado al inicio]" <<endl;
                }));

                menuInternoA.add_option(MenuOption("Agregar al final", [&](MenuOptionArguments args) {
                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();

                    lista -> insertarFinal(i -> funcionPrincipalEnteros("Ingrese un valor: "));
                    lista->imprimirInicio();
                    cout << "\n[elemento agregado al final]" <<endl;
                }));

                menuInternoA.add_option(MenuOption("Agregar por indice", [&](MenuOptionArguments args) {
                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                    IngresoDatos<int, float> *in = new IngresoDatos<int, float>();
                    int indice;
                    lista->imprimirInicio();
                    do {

                        indice = in->funcionPrincipalEnteros("Ingrese el indice donde desea agregarlo: ");
                    
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                    

                        break;
                    } while (true);

                    lista -> insertar(i -> funcionPrincipalEnteros("Ingrese un valor: "), indice);
                    lista->imprimirInicio();
                    cout << "\n[elemento agregado en la posicion " << indice << " ]" <<endl;
                }));

                break;
            } while (true);
        }  

        menuInternoA.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInternoA.stop();
        }, false));

        menuInternoA.display();

    }));


    menu.add_option(MenuOption("Eliminar Datos", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuInternoB("Eliminar datos");

        
        menuInternoB.add_option(MenuOption("Eliminar inicio", [&](MenuOptionArguments args) {
            if(lista->estaVacio()){
                lista -> eliminarInicio();
            }else{
                lista->imprimirInicio();
                lista->eliminarInicio();
                lista->imprimirInicio();
                cout << "\n[elemento eliminado al inicio]" <<endl;
            }
        }));

        menuInternoB.add_option(MenuOption("Eliminar final", [&](MenuOptionArguments args) {
            if(lista->estaVacio()){
                lista -> eliminarFinal();
            }else{
                lista->imprimirInicio();
                lista -> eliminarFinal();
                lista->imprimirInicio();
                cout << "\n[elemento eliminado al final]" <<endl;
            }
        }));

        menuInternoB.add_option(MenuOption("Eliminar por indice", [&](MenuOptionArguments args) {

            if(lista->estaVacio()){
                lista -> eliminarInicio();
            }else{
            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
            int indice;
            lista->imprimirInicio();

            do {
                    indice = i -> funcionPrincipalEnteros("Ingrese un valor: ");
                
                    break;
            } while (true);

            cout<<"\n";

            lista -> eliminar(indice);
            lista->imprimirInicio();
            cout << "\n[elemento eliminado en la posicion " << indice << " ]" <<endl;
            }
        }));

        menuInternoB.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInternoB.stop();
        }, false));

        menuInternoB.display();

    }));

    menu.add_option(MenuOption("Imprimir Datos", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuInternoC("Imprimir datos");

        menuInternoC.add_option(MenuOption("Imprimir desde la cabeza", [&](MenuOptionArguments args) {
            lista->imprimirInicio();
        }));

        menuInternoC.add_option(MenuOption("Imprimir desde la cola", [&](MenuOptionArguments args) {
            lista->imprimirFinal();
        }));

        menuInternoC.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInternoC.stop();
        }, false));

        menuInternoC.display();

    }));


    menu.add_option(MenuOption("Busco Datos", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuInternoD("Submenu");

        
        menuInternoD.add_option(MenuOption("Buscar Dato", [&](MenuOptionArguments args) {

            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
            int indice;
            lista->imprimirInicio();

            do {
                    indice = i -> funcionPrincipalEnteros("Ingrese el valor que desee encontrar: ");
                
                    break;
            } while (true);

            cout<<"\n";
            lista->imprimirBuscar(indice);

        }));
    

        menuInternoD.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInternoD.stop();
        }, false));

        menuInternoD.display();
    }));

    menu.add_option(MenuOption("Sacar promedio", [&](MenuOptionArguments args) {

            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
            int indice;
            lista->imprimirInicio();
            cout<<"\n";
            cout<<"El promedio de su lista es " <<lista->promedio()<<endl;

    }));
    
    //!Funcion salida del menu
    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

