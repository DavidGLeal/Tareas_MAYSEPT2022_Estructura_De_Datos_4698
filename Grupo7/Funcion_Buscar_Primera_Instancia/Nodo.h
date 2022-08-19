#pragma once 

class Nodo {
public:
	Nodo(int val, Nodo*);
	friend class Lista;
public:
	int valor;
	Nodo* siguiente;
};