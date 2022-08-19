//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H


#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu.cpp"
#include "OpcionMenu.cpp"
#include "Proceso.cpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    
    Proceso *p = new Proceso();
    //!Creo objeto menu. Este manejara las opciones
    Menu menu("Calculadora - menu");
   
    menu.add_option(MenuOption("1. Recibir expresion", [&](MenuOptionArguments args) {
        
            cout<< "Bienvenido. Si se tiene alguna duda de la sintaxis que desea recibir el programa";
            cout<< " ir al apartado de \"Consultar funciones\""<<endl;
            cout<< "\nIngrese la expresion: ";
            p->recibirExpresion();
    }));


    menu.add_option(MenuOption("2. Convertir a prefija o postfija", [&](MenuOptionArguments args) {
        
        if(!(p->estaVacia())){
            system("CLS");
            Menu menuInterno("Submenu");

            
            menuInterno.add_option(MenuOption("1. Postfija", [&](MenuOptionArguments args) {
                
                if(!(p->getPostfija()->estaVacia())){
                    p->imprimirNotacion(p->getPostfija());
                }else{
                    cout << "La expresion postfija es: ";
                    p->setPostfija(p->convertirPostfija(p->getInfija()));
                    p->imprimirNotacion(p->getPostfija());
                }

            }));
            
            menuInterno.add_option(MenuOption("2. Prefija", [&](MenuOptionArguments args) {

                cout << "La expresion prefija es: ";
                p->setPrefija(p->convertirPrefija(p->getInfija()));
                p->imprimirNotacion(p->getPrefija());

            }));

            menuInterno.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
                menuInterno.stop();
            }, false));

            menuInterno.display();
        }else{
            cout << "\nObjeto vacio "<<endl;
        }
    }));


    //!Submenus
    menu.add_option(MenuOption("3. Resolver", [&](MenuOptionArguments args) {

        if(!(p->estaVacia())){

            if(!(p->getPostfija()->estaVacia())){
                cout << "La expresion resuelta de"<<endl;
                p->imprimirNotacion(p->getInfija());
                cout << "\nes:"<<endl;
                p->resolverPost(p->getPostfija());

            }else{
                p->setPostfija(p->convertirPostfija(p->getInfija()));
                cout << "La expresion resuelta de"<<endl;
                p->imprimirNotacion(p->getInfija());
                cout << "\nes:"<<endl;
                p->resolverPost(p->getPostfija());
            }
        }else{
            cout << "\nObjeto vacio "<<endl;
        }
        
    }));

    menu.add_option(MenuOption("4. Consultar funciones", [&](MenuOptionArguments args) {
        
        cout << "Las operaciones basicas aritmeticas son + (suma), - (resta), * (multiplicacion). / (division)"<<endl;
        cout << "Las funciones de exponente estan definidad como ^, y la raiz se escribe como \"Indice\" rt \"Radicando\""<<endl;
        cout << "Se encuentran definidas las funciones trigonometricas de: seno(sin/sen), coseno(cos), tangente(tan)"<<endl;
        cout << "cosecante (csc), secante (sec), cotangente (ctg)."<<endl;
        cout << "seno hiperbolico (sinh), coseno hiperbolico (cosh), tangente hiperbolica (tanh)"<<endl;
        cout << "arco seno (arcsin/arcsen), arco coseno (arcos), arco tangente (arctan)"<<endl;
        cout << "Funciones de logaritmo como: logaritmo natural (ln), logaritmo base 10 (log10), y logaritmo de cualquier base \"Base\" log \"Argumento\" "<<endl;

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