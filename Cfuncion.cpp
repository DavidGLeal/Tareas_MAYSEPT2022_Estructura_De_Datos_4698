/*ESPE
*Enunciado del problema:
*   Crear una funcion que reciba como parametro un String, y conforme digite el usuario.
*   retornar un entero o un flotante.
*Autor 
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   10-05-2022
*Fecha de modificacion
*   10 - 05 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#ifndef CFUNCION_H
#define CFUNCION_H


#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;

class Funcion{
    
    private:

    public:
        Funcion();

        int devolverEntero(string str);
        float devolverFlotante(string str);
        void identificador();
};

Funcion::Funcion(){
    
}

int Funcion::devolverEntero(string string){
    return stoi(string);
}

float Funcion::devolverFlotante(string str){
    return std::stof(str);
}

void Funcion::identificador(){
    string str;
    int tipo=0;
    int bol = 0;
    cout << "Ingresa tu string: ";
    cin >> str;

 
    while (bol == 0){

        cout << "\n 1) Entero \n 2) Flotante \n";
        cout << "Ingresa el tipo de dato al que quieres convertir: ";
        cin >> tipo;

        if(tipo!=1 && tipo!=2){
            cout << "Opcion invalida. Vuelva a intentarlo";
            system("PAUSE");
            system("CLS");
            
        }else{
            ++bol;
        }
    }

    if(tipo == 1){
        cout << devolverEntero(str);
    }else if (tipo == 2){
        cout << devolverFlotante(str);
    }
}

int main(){

    Funcion *fun = new Funcion();

    fun -> identificador();

    return 0;
}

#endif