
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H
//!EJEMPLO DE CREACION DE MENU

#define NOMINMAX 1


#include <iostream>
#include <limits>
#include "4Menu.cpp"
#include "4OpcionMenu.cpp"
#include "3Tienda.cpp"
#include "3Stock.cpp"
#include "5IngresoDatos.hpp"

#include <iostream>

using namespace std;

Tienda* datosDefecto();

int main(int argc, char **argv) {
    
    Tienda *tienda = datosDefecto();

    //Tienda *tiendaVacia = new Tienda();

    //!Creo objeto menu. Este manejara las opciones
    Menu menu("------- Bienvenidos al programa que genera correos -------");



    menu.add_option(MenuOption("Usuarios ", [&](MenuOptionArguments args) {
    
        system("CLS");
        //Submenu Usuarios
        Menu menuUsuarios("Usuarios");

            menuUsuarios.add_option(MenuOption("Agregar usuario", [&](MenuOptionArguments args) {
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();

                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *k = new IngresoDatos<int, float>();
                 IngresoDatos<int, float> *p = new IngresoDatos<int, float>();

                char* nombre;
                char* apellido;
                double presupuesto;
                long cedula;

                do{

                        nombre = i->funcionMixta("\nIngrese el nombre de la persona: ");

                        apellido = j->funcionMixta("\nIngrese el apellido de la persona: ");

                        presupuesto = k->funcionPrincipalFlotantes("\n Ingrese el presupuesto");

                        cedula = k->funcionPrincipalEnteros("\nIngrese la cedula: ");
                    

                        break;
                } while (true);

                    
                Persona *nueva = new Persona(nombre, apellido, presupuesto, cedula);
                tienda->getStock()->getPersonas()->insertarFinal(nueva);

                cout<< "\n ---Se agrego con exito--- \n" <<endl;

            }));

            menuUsuarios.add_option(MenuOption("Ver Usuarios", [&](MenuOptionArguments args) {
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();
            }));

            menuUsuarios.add_option(MenuOption("Generar correo", [&](MenuOptionArguments args) {
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();

                  IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        char* nombre;

                        do{

                        nombre = i->funcionMixta("\nIngrese el nombre de la persona que desea generar email ");    

                        break;
                    } while (true);

                    if( tienda->personasPorNombreIgual(nombre)->obtenerPrimero()->getSiguiente() != nullptr){
                        tienda->personasPorNombreIgual(nombre)->obtenerPrimero()->getValor()->generarCorreo();
                        tienda->personasPorNombreIgual(nombre)->obtenerPrimero()->getSiguiente()->getValor()->generarCorreoRepetido();
                    }else{
                        tienda->personasPorNombreIgual(nombre)->obtenerPrimero()->getValor()->generarCorreo();
                    }    

                    cout<< "\n---Correo generado---\n"<<endl;
            }));



            menuUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuUsuarios.stop();
            }, false));

            //Mostrar menu
            menuUsuarios.display();
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

Tienda* datosDefecto(){

    Persona *p1 = new Persona("Matias", "Manzin", 100, 100000);
    Persona *p2 = new Persona("Lionel", "Messi", 5000, 0000001);
    Persona *p3 = new Persona("Edward", "Tech", 15, 22222222);


    ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
    personas->insertarFinal(p1);
    personas->insertarFinal(p2);
    personas->insertarFinal(p3);


    Stock *stock = new Stock();

    stock->setPersonas(personas);

    Tienda *t = new Tienda();
    t->setStock(stock);

    return t;
}
