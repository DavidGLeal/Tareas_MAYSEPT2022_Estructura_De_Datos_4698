#include <iostream>
#include <regex>
#include "1Pila.hpp"
using namespace std;
#pragma once
   
class Regex{
    private:
        int longitud=0;
    public:
        Regex(){

        }

        ~Regex(){
            free(this);
        }

        Pila<string>* fragmento(const string &a);

        bool compararLongitudes(int l);

        //?Funcion de numeros

        bool esUnNumero(const string &a);

        //!Funciones de identificacion de operandos

        bool esUnMas(const string &a);

        bool esUnMenos(const string &a);

        bool esUnaDivision(const string &a);

        bool esUnaMultiplicacion(const string &a);

        bool esUnSeno(const string &a);

        bool esUnCoseno(const string &a);

        bool esUnTangente(const string &a);

        bool esUnCosecante(const string &a);

        bool esUnSecante(const string &a);

        bool esUnCotangente(const string &a);

        bool esUnSenh(const string &a);

        bool esUnCosh(const string &a);

        bool esUnTanh(const string &a);

        bool esUnln(const string &a);

        bool esUnlog10(const string &a);

        bool esUnlog(const string &a);

        bool esUnOperando(const string &a);

        bool esUnExponente(const string &a);

        bool esUnaRaiz(const string &a);

        bool esUnSigno(const string &a);

        bool esUnBinario(const string &a);

        bool esUnParentesisInicial(const string &a);

        bool esUnParentesisFinal(const string &a);

        bool noEsBinario(const string &a);

        bool esUnFormatoEspecial(const string &a);

        bool excepciones(const string &s);

        bool excepcionesBinarios(const string &s);

        bool excepcionesParentesis(const string &s);

        int parentesisAbiertos(const string &s);

        int parentesisCerrados(const string &s);

        bool esUnArcSen(const string &a);

        bool esUnArcCos(const string &a);

        bool esUnArcTan(const string &a);

        bool esUnPi(const string &a);

        bool esUne(const string &a);
      
};