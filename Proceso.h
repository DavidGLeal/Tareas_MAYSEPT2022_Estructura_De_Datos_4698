#include <iostream>
#include "1Pila.hpp"
#include <conio.h>
#include <string>
#include <cstring>
#include "Regex.cpp"
#include "Calculadora.cpp"

using namespace std;
#pragma once
   
class Proceso{
    private:
        Pila<string> *infija = new Pila<string>();
        Pila<string> *postfija = new Pila<string>();
        Pila<string> *prefija = new Pila<string>();
        Regex *r = new Regex();
        Calculadora *c = new Calculadora();

    public:

    Proceso(){
    }

    void evaluarPostfija();

    int pNumero();

    ~Proceso(){
        
    }

    Pila<string> *getInfija();
    void setInfija(Pila<string> *i);

    Pila<string> *getPostfija();
    void setPostfija(Pila<string> *post);

    Pila<string> *getPrefija();
    void setPrefija(Pila<string> *pre);

    bool recibirExpresion();

    Pila<string>* convertirPostfija(Pila<string> * posf);

    Pila<string>* convertirPrefija(Pila<string> * pre);

    bool esPrioritario(string &uno, string &dos);

    int pMultiplicacionDivision();

    int pSumaResta();

    int pExponenteRaiz();

    int pParentesis();

    int pTrigonometricasLog();

    int operadores(const string &a);

    int prioridades(int operador);

    void reemplazaString(string& subject, const string& search, const string& replace);

    void reemplazoSignos(string& str);

    bool buscoSignos(string& str);

    void reemplazoMenos(string& str);

    int pSigno();

    void resolverPost(Pila<string> * p);
    void resolverPre(Pila<string> * p);

    double pi();

    double e();

    void imprimirNotacion(Pila<string> * p);

    bool estaVacia();

    void eliminarEspacios(string& str);

};