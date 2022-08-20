#pragma once
#include <iostream>

using namespace std;

class IngresarDatos
{
private:
public:
    IngresarDatos();
    ~IngresarDatos();
    int ingresarDatos(const char* prompt);
    int ingresarDatosLim(const char* prompt, int _limite);
    string ingresarDatosNumSt(const char* prompt, int _limite);
    float ingresarDatosF(const char* prompt, int _limite);
    string ingresarDatosS(const char* prompt);
    string ingresarDatosStringPermisivo(const char* prompt);
    string ingresarDatosOculto(const char* prompt);
};