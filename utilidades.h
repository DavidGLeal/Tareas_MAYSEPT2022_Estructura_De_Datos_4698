#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <exception>
#include <conio.h>

#ifndef _MSC_VER
#define _getch getch
#endif

int convertirEnEntero(std::string cadena)
{
    int numero = 0;
    int multiplo = 1;
    std::string cadenaReversa = cadena;

    if (cadena.find(".") != std::string::npos) {
        cadenaReversa = cadena.substr(0, cadena.find("."));
    }

    std::reverse(cadenaReversa.begin(), cadenaReversa.end());

    for (const char c : cadenaReversa) {
        

        if ((c < '0' || c > '9') && c != '-') {
            if (numero)
                break;
            else
                continue;
        }

        if (c == '-') {
            if (numero) {
                numero = -numero;
                break;
            }
        } else {
            numero += (c - '0') * multiplo;
            multiplo *= 10;
        }
    }

    return numero;
}

double convertirEnReal(std::string cadena)
{
    double rez = 0, fact = 1;
    

    if (cadena.at(0) == '-') {
        fact = -1;
        cadena = cadena.substr(1, cadena.length() - 1);
    }

    bool punto = false;
    int indice = 0;

    for (const char c : cadena) {
        int ascii = (int)c;

        if (c == '.' || c == ',') {
            if (punto || (!punto && indice == 0)) {
                throw std::runtime_error("numero real incorrecto");
            }

            punto = true;
            indice++;
            continue;
        }

        if (!isdigit(c)) {
            throw std::runtime_error("numero real incorrecto");
        }

        int d = c - '0';

        if (d >= 0 && d <= 9) {
            if (punto) fact /= 10.0f;
            rez = rez * 10.0f + static_cast<double>(d);
        }

        indice++;
    }

    double resultado = rez * fact;

    return resultado;
}

std::string leerCadenaNumerica(const std::string mensaje) {
    std::string resultado;
    int longitud = 0;

    std::cout << mensaje;

    while (true) {
        int ascii = _getch();

        if (ascii == 0) {
            ascii = _getch();
        }

        if (ascii == 8) {
            if (longitud == 0) {
                continue;
            }

            std::cout << "\b \b";
            resultado.pop_back();
            longitud--;
            continue;
        } else if (ascii == 13) {
            if (resultado.at(resultado.length() - 1) == '.') {
                continue;
            }

            break;
        }
        
        if ((ascii >= 48 && ascii <= 57) || ascii == 45 || ascii == 46 || ascii == 127) {
            if (ascii == 46 && resultado.find(".") != std::string::npos) {
                continue;
            }

            if (ascii == 46 && longitud == 0) {
                continue;
            }

            if (ascii == 45 && longitud != 0) {
                continue;
            }

            resultado.push_back(static_cast<char>(ascii));
            longitud++;
            std::cout << static_cast<char>(ascii);
        }
    }

    return resultado;
}