/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  05 DE AGOSTO DE 2022
* FECHA DE Entrega: 05 DE AGOSTO DE 2022
* Version: 2
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#pragma once
#include "Caballo.h"
#include <conio.h>
#include<iostream>
#include<random>
using namespace std;

/* Un constructor */
Caballo::Caballo(int x, int y): x(x), y(y), tablero(new char*[8]){
    for (int i = 0; i < 8; i++)
        *(tablero + i) = new char[8];
}

Caballo::Caballo(){
}

/**
 * Devuelve el valor de la variable x.
 * 
 * @return El valor de la variable privada x.
 */
int Caballo::getX(){
    return this->x;
}

/**
 * Devuelve el valor y del objeto.
 * 
 * @return El valor de la variable privada y.
 */
int Caballo::getY(){
    return this->y;
}

/**
 * 
 * Toma un parámetro, un `int` llamado `n`. Establece el miembro `x` de la clase en el
 * valor de `n`
 * 
 * @param n El nuevo valor para la coordenada x.
 */
void Caballo::setX(int n){
    this->x = n;
}

/**
 * Establece el valor de la variable y.
 * 
 * @param n El nuevo valor de la coordenada y.
 */
void Caballo::setY(int n){
    this-> y = n;
}

void Caballo::mover(char** tablero, Caballo& c, Caballo& c1) {

    //Funcion recursiva.
    moverCaballo(c, c.x, c.y);


    /* Comprobando si los dos caballos se han encontrado. */
    if (validarEncuentro(c, c1)) {
        exito = true;
    }

    //Impresion de coordenadas.
    cout << c.x << " " << c.y << endl;
    cout << c1.x << " " << c1.y << endl;

    imprimirCaballos(c, c1);

    /* Comprobando si los dos caballos se han encontrado. Si tienen, imprime las coordenadas de la
    reunión. Si no lo han hecho, vuelve a llamar a la función. */
    if (exito) {
        cout << "Encuentro: " << endl;
        cout << '(' << c.x << "," << c.y << ')' << endl;
        return;
    }
    else {

        //Recursividad.
        mover(tablero, c, c1);
    }

}

/**
 * Toma una referencia a un objeto Caballo y dos números enteros, y mueve el objeto Caballo a una
 * ubicación aleatoria en el tablero, y si la nueva ubicación no es válida, lo vuelve a mover a la
 * ubicación original y vuelve a intentarlo.
 * 
 * @param c es el objeto de la clase Caballo
 * @param x coordenada x del caballo
 * @param y coordenada y del caballo
 * 
 * @return Nada
 */
void Caballo::moverCaballo(Caballo& c, int x, int y)
{   
    // Llamo, de la libreria random, a un generador de numeros de entre 0 y 7. 
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 7);

    //Lo guardo en a.
    int a = dist(mt);

    //Con a, vamos a replicar los movimientos del caballo.
    //Sabemos que en x se movera 2 casillas y en y solo 1 originalmente
    //De alli, creamos variaciones.

    switch (a){
        case 0: {
            c.x += 2;
            c.y += 1;
            break;
        }
        case 1: {
            c.x += 2;
            c.y -= 1;
            break;
        }
        case 2: {
            c.x += 1;
            c.y += 2;
            break;
        }
        case 3: {
            c.x += 1;
            c.y -= 2;
            break;
        }
        case 4: {
            c.x -= 2;
            c.y += 1;
            break;
        }
        case 5: {
            c.x -= 2;
            c.y -= 1;
            break;
        }
        case 6: {
            c.x -= 1;
            c.y += 2;
            break;
        }
        case 7: {
            c.x -= 1;
            c.y -= 2;
            break;
        }
        default:
            break;
    }

   /* Comprobando si la nueva posición es válida, si no lo es vuelve a la posición original y vuelve a
   intentarlo. */
    if (validarFueraTablero(c.x, c.y)) {
        return;
    }else {
       /* Establezco las coordenadas x e y del objeto en las coordenadas originales. */
        c.x = x;
        c.y = y;

        //Recursion.
        moverCaballo(c, c.x, c.y);
    }

}

/**
 * Si las coordenadas x e y del primer caballo son iguales a las coordenadas x e y del segundo caballo,
 * devuelve verdadero, de lo contrario, devuelve falso
 * 
 * @param c Caballo& c
 * @param c2 el segundo caballo
 * 
 * @return un valor booleano.
 */
bool Caballo::validarEncuentro(Caballo& c, Caballo& c2) {
    if (c.x == c2.x && c.y == c2.y)
        return true;
    else
        return false;
}

/**
 * Comprueba si las coordenadas están dentro del rango del tablero
 * 
 * @param x1 coordenada x de la pieza
 * @param y1 La coordenada y de la pieza que quieres mover.
 * @param x2 La coordenada x del cuadrado de destino.
 * @param y2 La coordenada y del cuadrado de destino.
 * 
 * @return un valor booleano.
 */
bool Caballo::validarAmbos(int x1, int y1, int x2, int y2)
{
    if (x1 > 7 || x1 < 0)
        return false;
    if (x2 > 7 || x2 < 0)
        return false;
    if (y1 > 7 || y1 < 0)
        return false;
    if (y2 > 7 || y2 < 0)
        return false;
    else
        return true;
}

/**
 * Comprueba si la posición está fuera del tablero.
 * 
 * @param x1 La coordenada x de la pieza.
 * @param y1 la coordenada y de la pieza
 * 
 * @return un valor booleano.
 */
bool Caballo::validarFueraTablero(int x1, int y1)
{
    if (x1 > 7 || x1 < 0)
        return false;
    if (y1 > 7 || y1 < 0)
        return false;
    else
        return true;
}

void Caballo::imprimirCaballos(Caballo& x, Caballo& y) {
    cout << endl;

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {

        
           /* Imprimiendo el tablero. */
            if (i == x.x && j == x.y)
                *(*(tablero + j) + i) = 'C';
            else if (i == y.x && j == y.y)
                *(*(tablero + j) + i) = 'C';
            else
                *(*(tablero + j) + i) = '*';
            cout << *(*(tablero + j) + i) << " ";

        }
        cout << '\n';
    }
    cout << endl;
}


/**
 * Resuelve el problema
 */
void Caballo::resolver(){

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        cout << "Caballo 1\n" << endl;
    x1 = validarNum("No. de Fila a empezar: ");
        cout << endl;
    y1 = validarNum("No. de Columna a empezar: ");
        cout << "\nCaballo 2\n" << endl;
    x2 = validarNum("No. de Fila a empezar: ");
        cout << endl;
    y2 = validarNum("No. de Columna a empezar: ");

    //Creo tablero
    char** tablero = nullptr;

    //Creo caballos
    Caballo c(x1, y1);
    Caballo c2(x2, y2);

    //Imprimo
    c.imprimirCaballos(c, c2);

   /* Comprobando si los dos caballos están en la misma posición. Si lo son, imprime un mensaje. Si no
   lo son, llama a la función mover. */
    if (c.validarEncuentro(c, c2)) {
        cout << "Los caballos se encuentran en la misma posicion" << endl;
    }
    else {
        c.mover(tablero, c, c2);
        c.imprimirCaballos(c, c2);
    }

}

/**
 * Toma una cadena como argumento y devuelve un número entero. Valida que llegue de 0 a 7.
 * 
 * @param msj El mensaje que se mostrará al usuario.
 * 
 * @return el valor de la variable datos.
 */
int Caballo::validarNum(const char* msj) {
    char* datos = new char[30];
    int i = 0;
    char c;
    printf("%s", msj);
    while ((c = getch()) != 13) {
        if (c >= '0' && c < '8') {
            printf("%c", c);
            *(datos + i++) = c;
        }
    }
    return atoi(datos);
}