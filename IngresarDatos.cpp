#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "IngresarDatos.h"
using namespace std;

IngresarDatos::IngresarDatos(){
}
IngresarDatos::~IngresarDatos(){
    delete this;
}
int IngresarDatos::ingresarDatos(const char* prompt){
    cout << "Ingrese el valor " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    while ((input = getch()) != 13 && contador < 5)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return atoi(opcion);
}
int IngresarDatos::ingresarDatosLim(const char* prompt, int _limite){
    cout << "Para evitar el desbordamiento de memoria, el máximo de ingreso es de " << _limite << " cifras."<<endl;
    cout << "Ingrese el valor " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13 && contador < _limite)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return atoi(opcion);
}
string IngresarDatos::ingresarDatosNumSt(const char* prompt, int _limite){
    cout << "Ingrese un numero de cedula valido para el Estado Ecuatoriano (10 digitos)"<<endl;
    cout << "Ingrese " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false, primero = false, segundo = false;
    while ((input = _getch()))
    {
        if (input >= '0' && input <= '9' && contador < _limite)
        {
            if (contador == 0 && (input >= 48 && input <= 50))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
            }
            else if(contador == 1 && (opcion[0] == 50) && (input >= 48 && input <= 52))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
                
            }
            else if(contador == 1 && (opcion[0] != 50) && (input >= 48 && input <= 57))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
                
            }
            else if ((contador > 1) && (input >= 48 && input <= 57))
            {
                printf("%c", input);
                opcion[i++] = input;
                contador++;
                primerIngreso = true;
            }
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
                contador--;
            }
        }
        else if (input == 13)
        {
            if (contador == _limite)
            {
                break;
            }
        }
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
float IngresarDatos::ingresarDatosF(const char* prompt, int _limite){
    cout << "Para evitar el desbordamiento de memoria, el máximo de ingreso es de " << _limite << " cifras."<<endl;
    cout << "Ingrese el valor " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0, contador = 0;
    bool primerIngreso = false;
    bool usado = false;
    while ((input = _getch()) != 13 && contador < _limite)
    {
        if (input >= '0' && input <= '9')
        {
            printf("%c", input);
            opcion[i++] = input;
            contador++;
            primerIngreso = true;
        }
        else if (input == '.' && usado == false)
        {
            usado = true;
            printf("%c", input);
            opcion[i++] = input;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                if (opcion[i] == '.')
                {
                    usado = false;
                }
                opcion[i--] = input;
                contador--;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return atof(opcion);
}
string IngresarDatos::ingresarDatosS(const char* prompt){
    cout << "Ingrese " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 65 && input <= 168 || input == 32)
        {
            printf("%c", input);
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
string IngresarDatos::ingresarDatosStringPermisivo(const char* prompt){
    cout << "Ingrese " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 65 && input <= 168 || input == 32 || input == 46 || input >= 48 && input <= 57)
        {
            printf("%c", input);
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}
string IngresarDatos::ingresarDatosOculto(const char* prompt)
{
    cout << "Su clave no puede tener caracteres especiales."<<endl;
    cout << "Ingrese " << prompt << ": ";
    char *opcion = new char, input;
    int i = 0;
    bool primerIngreso = false;
    while ((input = _getch()) != 13)
    {
        if (input >= 65 && input <= 168 || input == 32 || input == 46 || input >= 48 && input <= 57)
        {
            printf("%c", '*');
            opcion[i++] = input;
            primerIngreso = true;
        }
        else if (input == 8 && primerIngreso == true)
        {
            if (i > 0) {
                printf("%s", "\b \b");
                opcion[i--] = input;
            }
        }
        
    }
    opcion[i] = '\0';
    printf("\n");
    return opcion;
}