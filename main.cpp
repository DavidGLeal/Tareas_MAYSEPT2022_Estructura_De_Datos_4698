
/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H

#define NOMINMAX 1

#include <conio.h>
#include <iostream>
#include <limits>
#include "4Menu.cpp"
#include "4OpcionMenu.cpp"
#include "3Tienda.cpp"
#include "3Stock.cpp"
#include "5IngresoDatos.h"
#include "6Marquesina.h"
//#include "8Imagen.h"
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

#include <iostream>
#define USER "admin"
#define PASSWORD "admin"
using namespace std;

Tienda* datosDefecto();


int main(int argc, char **argv) {
    
    Tienda *tienda = datosDefecto();
    //Tienda *tiendaVacia = new Tienda();

    string usuario, password;
    int contador = 3;
    bool ingreso = false;

    do{
        system("cls");

        cout<<"\t\t\t~~ LOGIN DE USUARIO ~~"<<endl;
        cout<<"\t\t\t  ----------------  "<<endl;

        //Usuario
        cout<< "\n\tUsuario: "; 
        getline(cin, usuario);

        //Contraseña
        cout<< "\n\tClave: "; 
        //getline(cin, password);
        char caracter;
        caracter= getch();
        password="";

        //Lectura hasta precionar enter
        while (caracter != 13){
            if(caracter != 8){
            password.push_back(caracter);
            cout<<"*";
            }else{
                if(password.length()>0){
                cout<<"\b \b";
                password = password.substr(0, password.length()-1);
                }
            }
            caracter= getch();
        }

        //Condicion
        if( usuario == USER && password == PASSWORD){
            ingreso=true;

        } else{
            cout<<"\n\tEl usuario y/o password son incorrectos"<<endl;
            cout<< "\n\n\t Quedan " << contador << " intentos"<<endl;
            cin.get();
            contador--;
        }

    }while (ingreso == false && contador >= 0);

    if(ingreso == false){
        cout <<"\n\tNo se pudo ingresar al sistema"<<endl;
    }else{
        cout<<"\n\tBienvenido al sistema"<<endl;

        //!Creo objeto menu. Este manejara las opciones
        Menu menu("     ~~~~~~~~~~~~~~~~~~~~~ Bienvenidos al programa de compra de Celulares ~~~~~~~~~~~~~~~~~~~~~      ");

        //!Funciona menu completo
        menu.add_option(MenuOption("    -> Stock", [&](MenuOptionArguments args) {
            system("CLS");
            //Submenu Stock
            Menu menuStock("Stock");

                //!Funciona
                menuStock.add_option(MenuOption("   - Ver Stock", [&](MenuOptionArguments args) {
                    tienda->getStock()->verCelulares();
                    //tienda->getStock()->verStock();
                    //cout<<tienda->getStock()->getCelulares()->obtenerLongitud()<<endl;
                }));

                //!Funciona
                menuStock.add_option(MenuOption("   - Agregar a Stock", [&](MenuOptionArguments args){


                    system("CLS");
                    Menu menuInterno(" Agregado");

                    
                    menuInterno.add_option(MenuOption("     + Por teclado", [&](MenuOptionArguments args) {

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *k = new IngresoDatos<int, float>();

                        char* marca = new char[50];
                        marca[0] = '\0';
                        double precio;
                        int stock;

                        marca = i->funcionMixta("\n Ingrese la marca del celular: ");

                            if(marca[0] != '\0'){

                                precio = j->funcionPrincipalFlotantes("\n   Ingrese el precio del celular: ");

                                if(precio!= -1){

                                    stock = k->funcionPrincipalEnteros("\n  Ingrese la cantidad de ejemplares de este celular que existen: ");    
                                    
                                    if(stock != -1){

                                        if(tienda->stockCorrecto(stock)){
                                        Celular *nuevo = new Celular(marca, precio, stock);

                                        tienda->agregarCelularTienda(nuevo);
                                        }else{
                                            cout << "\n\n ~~~ El stock no puede ser 0 ~~~" <<endl;
                                        }
                                    }
                                }

                            }else{

                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                        delete [] marca;
                    }));

                    menuInterno.add_option(MenuOption("     + Por archivo", [&](MenuOptionArguments args) {

                        IngresoDatos<int, float> *d = new IngresoDatos<int, float>();
                        char* nombre = new char[50];
                        nombre[0] = '\0';

                        nombre = d->funcionMixta("\n Ingrese el nombre con extension, o arrastre el archivo que desea leer \n");

                        if(nombre[0] != '\0'){

                            tienda->importarCelulares(nombre);

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                    }));
                    

                    menuInterno.add_option(MenuOption("\n   + Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuInterno.stop();
                    }, false));

                    menuInterno.display();

                }));

                //!Funciona
                menuStock.add_option(MenuOption("   - Eliminar elemento del Stock", [&](MenuOptionArguments args) {

                    if(tienda->estaVacio()){
                        cout<< "    Tienda vacia. No hay nada que borrar" <<endl;
                    }else{

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                        char* nombre = new char[50];
                        nombre[0] = '\0';
                        double precio;
                        tienda->getStock()->verCelulares();
                        


                        nombre = i->funcionMixta("\n    Ingrese el nombre del celular que desea eliminar: ");    

                        if(nombre[0] != '\0'){
                            
                            precio = j->funcionPrincipalFlotantes("\n   Ingrese el precio del celular que desea eliminar: ");

                            if(precio != -1){
                            Celular* celu = new Celular(nombre, precio, 0);
                            tienda->eliminarCelularTienda(celu);
                            }

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                        delete [] nombre;

                    }
                }));
                
                //!Funciona
                menuStock.add_option(MenuOption("   - Busqueda", [&](MenuOptionArguments args) {
            
                    //Submenu Busqueda de Celulares
                    Menu menuBusquedaUsuarios("Busqueda");

                        //!Funciona
                        menuBusquedaUsuarios.add_option(MenuOption("Por Marca", [&](MenuOptionArguments args) {
                            
                            if(tienda->estaVacio()){

                                cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                            }else{

                                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                                char* nombre = new char[50];
                                nombre[0] = '\0';

                                
                                nombre = i->funcionMixta("\n    Ingrese la marca del celular que desea buscar: ");    

                                if(nombre[0] != '\0'){
                                    tienda ->buscarPorNombreCelular(nombre);
                                }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                }

                                delete [] nombre;
                            }
                            
                        }));
                        
                        //!Funciona
                        menuBusquedaUsuarios.add_option(MenuOption("Por Precio", [&](MenuOptionArguments args) {
                            
                            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                            double precio;

                            precio = i->funcionPrincipalFlotantes("\nIngrese el nombre de la persona que desea buscar: ");    

                            if(precio != 1){
                                tienda->buscarPorPrecioCelular(precio);
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                        }));
                        

                        
                        menuBusquedaUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuBusquedaUsuarios.stop();
                        }, false));

                        //Mostrar menu
                        menuBusquedaUsuarios.display();



                }));

                //!Funciona
                menuStock.add_option(MenuOption("   - Regresar a menu principal", [&](MenuOptionArguments args) {
                menuStock.stop();
                }, false));

                //Mostrar menu
                menuStock.display();

        }));


        menu.add_option(MenuOption("    -> Usuarios", [&](MenuOptionArguments args) {

            system("CLS");
            //Submenu Usuarios
            Menu menuUsuarios(" - Usuarios");

                menuUsuarios.add_option(MenuOption("    - Ver Usuarios", [&](MenuOptionArguments args) {
                    tienda->getStock()->getPersonas()->imprimirObjetoFinal();
                }));

                //!Funciona
                menuUsuarios.add_option(MenuOption("    - Agregar Usuario", [&](MenuOptionArguments args) {   
                    
                        system("CLS");
                    Menu menuInterno(" Agregado");

                    
                    menuInterno.add_option(MenuOption("     + Por teclado", [&](MenuOptionArguments args) {

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *k = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *l = new IngresoDatos<int, float>();

                        char* nombre = new char[50];
                        nombre[0] = '\0';
                        char* apellido = new char[50];
                        apellido[0] = '\0';
                        double presupuesto;
                        unsigned long cedula = 0;
                        nombre = i->funcionLetras("\n   Ingrese el nombre de la persona: ");

                            if(nombre[0] != '\0'){
                                apellido = j->funcionLetras("\n Ingrese el apellido de la persona: ");

                                if(apellido[0] != '\0'){

                                    presupuesto = k->funcionPrincipalFlotantes("\n  Ingrese el presupuesto de la persona: ");

                                    if(presupuesto!= -1){

                                        cedula = l->funcionPrincipalEnteros("\n Ingrese la cedula de la persona: ");

                                        if(cedula != -1){

                                            if(tienda->presupuestoCorrecto(presupuesto)){

                                                if(tienda->cedulaCorrecta(cedula)){
                         
                                                    Persona *nueva = new Persona(nombre, apellido, presupuesto, cedula);  
                                                    //cout<< cedula <<endl;
                                                    tienda->agregarPersonaTienda(nueva);
                                                }else{
                                                    cout<<"\n~~ La cedula es incorrecta. Recuerde que son 10 digitos ~~\n"<<endl;
                                                }

                                            }else{
                                                cout<<"\n~~ La persona posee un presupuesto demasiado bajo ~~\n"<<endl;
                                            }
                                        }

                                    }

                                }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                }
                            }else{

                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                        delete [] nombre;
                        delete [] apellido;
                    }));

                    menuInterno.add_option(MenuOption("     + Por archivo", [&](MenuOptionArguments args) {

                        IngresoDatos<int, float> *d = new IngresoDatos<int, float>();
                        char* nombre = new char[50];
                        nombre[0] = '\0';

                        nombre = d->funcionMixta("\n Ingrese el nombre con extension, o arrastre el archivo que desea leer \n");

                        if(nombre[0] != '\0'){

                            tienda->importarPersonas(nombre);

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                    }));
                    

                    menuInterno.add_option(MenuOption("\n   + Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuInterno.stop();
                    }, false));

                    menuInterno.display();
                    

                }));
                
                //!Funciona
                menuUsuarios.add_option(MenuOption("    - Eliminar Usuario", [&](MenuOptionArguments args) {
                    
                    if(tienda->estaVacio()){
                        cout<< "Tienda vacia. No hay nada que borrar" <<endl;
                    }else{

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *k = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *l = new IngresoDatos<int, float>();

                        char* nombre = new char[50];
                        nombre[0] = '\0';
                        char* apellido = new char[50];
                        apellido[0] = '\0';
                        tienda->getStock()->verPersonas();
                        double presupuesto;
                        long cedula;


                        nombre = i->funcionLetras("\n Ingrese solo el nombre de la persona que desea eliminar: ");    

                        if(nombre[0] != '\0'){
                            
                            apellido = j ->funcionLetras("\n Ingrese el apellido de la persona que desea eliminar: ");

                            if(apellido[0] != '\0'){

                                
                                presupuesto = k->funcionPrincipalFlotantes("\n  Ingrese el presupuesto de la persona que desea eliminar: ");

                                if(presupuesto!= -1){

                                    
                                    cedula = l->funcionPrincipalLong("\n Ingrese la cedula de la persona: ");

                                    if(cedula!= -1){

                                        Persona* per = new Persona(nombre, apellido, presupuesto, cedula);
                                        tienda->eliminarPersonaTienda(per);
                                    }

                                }

                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                        delete [] nombre;

                    }


                }));

                //!Funciona
                menuUsuarios.add_option(MenuOption("    - Buscar Usuarios", [&](MenuOptionArguments args) {
                    system("CLS");
                    //Submenu Busqueda de Usuarios
                    Menu menuBusquedaUsuarios("Busqueda");

                        //!Funciona
                        menuBusquedaUsuarios.add_option(MenuOption("    .- Por Nombre", [&](MenuOptionArguments args) {
                            
                            if(tienda->estaVacio()){

                                cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                            }else{

                                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                                char* nombre = new char[50];
                                nombre[0] = '\0';
                                char* apellido = new char[50];
                                apellido[0] = '\0';

                                //tienda->getStock()->getPersonas()->imprimirObjetoFinal();

                                nombre = i->funcionLetras("\n  Ingrese solo el nombre que desea buscar: ");    
                                
                                if(nombre[0] != '\0'){

                                    apellido = j->funcionLetras("\n Ingrese el apellido que desea buscar: ");

                                    if(nombre[0] != '\0'){
                                        tienda ->buscarPorNombrePersona(nombre, apellido);
                                    }else{
                                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                    }
                
                                }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                }

                                delete [] nombre;
                                delete [] apellido;
                            }

                            
                            //Stock *porNombre = new Stock();
                            //porNombre->setPersonas(tienda->personasPorNombreIgual(nombre));
                            //porNombre->informeCompraCelulares();
                            
                        }));
                        
                        //!Funciona
                        menuBusquedaUsuarios.add_option(MenuOption("    .-Por Presupuesto", [&](MenuOptionArguments args) {
                            
                            if(tienda->estaVacio()){

                                cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                            }else{

                                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                                double presupuesto;

                                presupuesto = i->funcionPrincipalFlotantes("\nIngrese el presupuesto de la persona que desea buscar: ");    

                                if(presupuesto != 1){
                                    tienda->buscarPorPresupuestoPersona(presupuesto);
                                }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                }    
                            }    

                        }));
                                    
                        menuBusquedaUsuarios.add_option(MenuOption("    - Regresar a menu Usuarios", [&](MenuOptionArguments args) {
                        menuBusquedaUsuarios.stop();
                        }, false));

                        //Mostrar menu
                        menuBusquedaUsuarios.display();
                }));

                menuUsuarios.add_option(MenuOption("    - Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuUsuarios.stop();
                }, false));
                /*
                //!Funciona
                menuUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                menuUsuarios.stop();
                }, false));
                */

                //Mostrar menu
                menuUsuarios.display();
        }));


        menu.add_option(MenuOption("    -> Comprar", [&](MenuOptionArguments args) {
            
            system("CLS");

            
            char* nombre = new char[50];
            nombre[0] = '\0';

            char* apellido = new char[50];
            nombre[0] = '\0';
            
            double presupuesto;
            int cedula;

            IngresoDatos<int, float> *a = new IngresoDatos<int, float>();
            IngresoDatos<int, float> *b = new IngresoDatos<int, float>();
            IngresoDatos<int, float> *c = new IngresoDatos<int, float>();
            IngresoDatos<int, float> *l = new IngresoDatos<int, float>();
            
            int ver = 0;
            while(ver == 0){

                Menu menuIngreso("\n~~~ Ingreso de datos para comprar ~~~");

                menuIngreso.add_option(MenuOption("Ingresar Datos", [&](MenuOptionArguments args) {

                    tienda->getStock()->getPersonas()->imprimirObjetoFinal();

                    nombre = a->funcionLetras("\n Ingrese solo nombre de la persona con la que relizaremos la compra: ");    

                    if(nombre[0] != '\0'){
                        
                        apellido = b->funcionLetras("\n Ingrese el apellido de la persona: ");

                        if(apellido[0] != '\0'){

                            presupuesto = c->funcionPrincipalFlotantes("\n Ingrese el presupuesto de la persona: ");

                            if(presupuesto!= -1){

                                    cedula = l->funcionPrincipalEnteros("\n Ingrese la cedula de la persona: ");

                                    if(cedula!= -1){

                                            Persona* c = tienda->getStock()->retornarPersonaporNombre(nombre, apellido, presupuesto, cedula);

                                        if(c != nullptr){
                                            cout<<"\n~~ Persona leida con exito ~~\n"<<endl;
                                            ++ver;
                                            menuIngreso.stop();
                                        }else{
                                            cout<<"\n~~ No existen coincidencias de esos datos ~~\n"<<endl;
                                        }
                                    }
            
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }    

                    }else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                }));

                
                menuIngreso.add_option(MenuOption("Cancelar", [&](MenuOptionArguments args) {
                    ver = 100;
                    menuIngreso.stop();
                }, false));

                menuIngreso.display();
            }

            //!Fin del recibo de datos datos para trabajar
            Persona *p = tienda->getStock()->retornarPersonaporNombre(nombre, apellido, presupuesto, cedula);

            if (ver != 100){

                Menu menuComprar("~~~ Menu de compra ~~~");


                    menuComprar.add_option(MenuOption("Recomendar compra", [&](MenuOptionArguments args) {
                        system("CLS");

                        //?Submenu Recomendaciones 

                        Menu menuRecomendaciones("Recomendaciones");

                            system("CLS");
                            //Submenu Recomendar celulares 
                            Menu menuReCelulares("Submenu Recomendar Celulares");

                            menuReCelulares.add_option(MenuOption(" - Recomendar automaticamente", [&](MenuOptionArguments args) {
                                
                                    
                                if(tienda->recomendarAutomatico(nombre, apellido, presupuesto, cedula)){

                                    system("pause");
                
                                    system("CLS");

                                    Menu menuInterno("~~~ Desea comprar alguno? ~~~");
                                    
                                    menuInterno.add_option(MenuOption("Si", [&](MenuOptionArguments args) {

                                            tienda->recomendarAutomatico(nombre, apellido, presupuesto, cedula);

                                            IngresoDatos<int, float> *o = new IngresoDatos<int, float>();
                                            IngresoDatos<int, float> *w = new IngresoDatos<int, float>();
                    
                                            char* celular = new char[50];
                                            int cantidad;

                                            celular = o->funcionMixta("\nIngrese el nombre del celular que desea comprar ");   

                                            Celular* c = tienda->getStock()->retornarCelularporNombre(celular);

                                            if(celular[0] != '\0'){
                                            
                                                cantidad = w->funcionPrincipalEnteros("\nIngrese cuantos items de este tipo desea comprar (si desea comprar solo 1, presione enter): ");

                                                if (cantidad == -1){
                                                    tienda->comprarCelular(p,c);
                                                }else{
                                                    tienda->comprarCelular(p,c,cantidad);
                                                }

                                            }else{
                                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                            }
                                        menuInterno.stop();
                                    }, false));
                                            

                                    menuInterno.add_option(MenuOption("No", [&](MenuOptionArguments args) {
                                        menuInterno.stop();
                                    }, false));

                                    menuInterno.display();

                                }   
                            
                            }));
                            
                            menuReCelulares.add_option(MenuOption(" - Recomendar por presupuesto a mayor", [&](MenuOptionArguments args) {
                                
                                if(tienda->estaVacio()){
                                        cout<< "Tienda vacia. No hay nada que recomendar" <<endl;
                                }else{

                                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        
                                double presupuesto;

                                presupuesto = i->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                                    if(presupuesto != -1){
                                        
                                        tienda->recomendarMayores(presupuesto);
                                    
                                    }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                    }    
                
                                }

                            }));
                            
                            menuReCelulares.add_option(MenuOption(" - Recomendar por presupuesto a menor", [&](MenuOptionArguments args) {
                            
                                if(tienda->estaVacio()){
                                        cout<< "Tienda vacia. No hay nada que recomendar" <<endl;
                                }else{

                                IngresoDatos<int, float> *t = new IngresoDatos<int, float>();
                        
                                double presupuesto;

                                presupuesto = t->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                                    if(presupuesto != -1){
                                        
                                        tienda->recomendarMenores(presupuesto);
                                    
                                    }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                    }    
                
                                }

                            }));

                            menuReCelulares.add_option(MenuOption(" - Regresar a menu de compra", [&](MenuOptionArguments args) {
                                menuReCelulares.stop();
                                menuRecomendaciones.stop();
                            }, false));

                            menuReCelulares.display();            
                        
                        menuRecomendaciones.display();
                    }));


                    menuComprar.add_option(MenuOption("Comprar celular", [&](MenuOptionArguments args) {
                                

                        tienda->getStock()->verStock();

                        char* celular = new char[50];
                        celular[0] = '\0';
                        int cantidad;

                        IngresoDatos<int, float> *c = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *q = new IngresoDatos<int, float>();

                        celular = c->funcionMixta("\nIngrese el nombre del celular que desea comprar ");   
                            Celular* ce = tienda->getStock()->retornarCelularporNombre(celular);
                            if(celular[0] != '\0'){
                                cantidad = q->funcionPrincipalEnteros("\nIngrese cuantos items de este tipo desea comprar (si desea comprar solo 1, presione enter): ");

                                    if (cantidad == -1){
                                    tienda->comprarCelular(p,ce);
                                }else{
                                    tienda->comprarCelular(p,ce,cantidad);
                                }

                            } else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }
                        
                    }));


                    menuComprar.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                    menuComprar.stop();
                    
                    delete [] nombre;
                    delete [] apellido;
                    }, false));

                menuComprar.display();
            }
        }));



        menu.add_option(MenuOption("    -> Mostrar informe de compras", [&](MenuOptionArguments args) {
            tienda->getStock()->informeCompraCelulares();
        }));

        menu.add_option(MenuOption("    -> Exportar datos", [&](MenuOptionArguments args) {
            
            system("CLS");
            Menu menuInterno(" Exportado");

            
            menuInterno.add_option(MenuOption(" + Exportar celulares", [&](MenuOptionArguments args) {

                system("CLS");
                Menu menuInterno1(" ~~~ Elija el formato del archivo a exportar ~~~");

                
                menuInterno1.add_option(MenuOption(".txt", [&](MenuOptionArguments args) {
                    tienda->exportarCelulares(".txt");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".csv", [&](MenuOptionArguments args) {
                    tienda->exportarCelulares(".csv");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".dat", [&](MenuOptionArguments args) {
                    tienda->exportarCelulares(".dat");
                    menuInterno1.stop();
                }, false));

                menuInterno1.display();

            }));
            
            menuInterno.add_option(MenuOption(" + Exportar Persona", [&](MenuOptionArguments args) {

                system("CLS");
                Menu menuInterno1(" ~~~ Elija el formato del archivo a exportar ~~~");

                
                menuInterno1.add_option(MenuOption(".txt", [&](MenuOptionArguments args) {
                    tienda->exportarPersonas(".txt");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".csv", [&](MenuOptionArguments args) {
                    tienda->exportarPersonas(".csv");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".dat", [&](MenuOptionArguments args) {
                    tienda->exportarPersonas(".dat");
                    menuInterno1.stop();
                }, false));

                menuInterno1.display();

            }));

            menuInterno.add_option(MenuOption(" + Informe de compra", [&](MenuOptionArguments args) {

                system("CLS");
                Menu menuInterno1(" ~~~ Elija el formato del archivo a exportar ~~~");

                
                menuInterno1.add_option(MenuOption(".txt", [&](MenuOptionArguments args) {
                    tienda->exportarInforme(".txt");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".csv", [&](MenuOptionArguments args) {
                    tienda->exportarInforme(".csv");
                    menuInterno1.stop();
                }, false));

                menuInterno1.add_option(MenuOption(".dat", [&](MenuOptionArguments args) {
                    tienda->exportarInforme(".dat");
                    menuInterno1.stop();
                }, false));

                menuInterno1.display();

            }));

            menuInterno.add_option(MenuOption("\n Regresar a menu principal", [&](MenuOptionArguments args) {
                menuInterno.stop();
            }, false));

            menuInterno.display();

        }));

        /*menu.add_option(MenuOption("    -> Ver imagen", [&](MenuOptionArguments args) {
            //!IMPLEMENTAR
            	initwindow(700, 600, "Grupo 2", 300, 300);
			//setviewport(0,0,800,200,1);
			setbkcolor(COLOR(170,223,101));
			clearviewport();
			readimagefile("Grupo2.jpg",100, 20, 600, 580);
			getch();
			return 0;
        }));*/

        menu.add_option(MenuOption("    -> Ayuda", [&](MenuOptionArguments args) {
            system("ProyectoCelulares.chm");
        }));

        //!Funcion salida del menu
        menu.add_option(MenuOption("    -> Salir", [&](MenuOptionArguments args) {
            
            Marquesina *m = new Marquesina("Gracias por usar el programa!");
            m ->bucleMarquesina();
            tienda->~Tienda();
            menu.stop();

        }, false));

        //!MOSTRAR MENU.
        menu.display(); 
        
    }
    
    cin.get();
    cin.get();

    return 0; 
}

Tienda* datosDefecto(){

    Persona *p1 = new Persona("Matias", "Manzin", 100,  1729010995);
    Persona *p2 = new Persona("Lionel", "Messi", 5000, 1722311071);
    Persona *p3 = new Persona("Edward", "Tech", 1500, 1867282736);

    Celular *c1 = new Celular("Alcatel", 40, 100);
    Celular *c2 = new Celular("Samsung", 1000, 30);
    Celular *c3 = new Celular("Motorola", 250, 50);
    Celular *c4 = new Celular("Iphone 12", 2000, 3);

    ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
    personas->insertarFinal(p1);
    personas->insertarFinal(p2);
    personas->insertarFinal(p3);

    ListaDobleC<Celular*> *celulares = new ListaDobleC<Celular*>();
    celulares->insertarFinal(c1);
    celulares->insertarFinal(c2);
    celulares->insertarFinal(c3);
    celulares->insertarFinal(c4);

    Stock *stock = new Stock();
    stock->setCelulares(celulares);
    stock->setPersonas(personas);

    Tienda *tienda = new Tienda();
    tienda->setStock(stock);
    //system("pause");

    return tienda;
}

