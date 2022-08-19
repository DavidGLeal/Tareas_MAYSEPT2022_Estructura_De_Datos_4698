#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
public:
	int getValor();
	Nodo*& getDerecha();
	Nodo*& getIzquierda();
	void setValor(int);
	void setDerecha(Nodo*);
	void setIzquierda(Nodo*);

private:
	int valor;
	Nodo* derecha;
	Nodo* izquierda;
};

