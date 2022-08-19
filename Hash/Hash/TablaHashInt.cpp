/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash cerrado de enteros y strings .
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 24-06-2022
	*Fecha de modificacion:
        * 29-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/
#pragma once 
#include <iostream>
#include "TablaHashInt.h"
#include "NodoEntero.h"
#include "NodoEntero.cpp"
#include <functional>

using namespace std;

TablaCerradaEnteros :: TablaCerradaEnteros(){
    tabla = new NodoCircularEntero*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaCerradaEnteros :: ~TablaCerradaEnteros(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;
}
void TablaCerradaEnteros::insertarCuadratico(int valor){
    int pos = hashCuadratico(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircularEntero(valor);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircularEntero(valor));
    }
}

void TablaCerradaEnteros::insertarLineal(int valor){
    int pos = hashlineal(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircularEntero(valor);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircularEntero(valor));
    }
}

void TablaCerradaEnteros::insertarDoble(int valor){
    int pos = hash2(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircularEntero(valor);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircularEntero(valor));
    }
}
void TablaCerradaEnteros::eliminar(int valor){
    int pos = hash(valor);
    NodoCircularEntero *aux = tabla[pos];
    while (aux == NULL)
    {
        pos++;
        aux = tabla[pos % NCASILLAS];
    }
    if(aux->getValor() == valor){
        tabla[pos] = tabla[pos]->getSig();
        delete aux;
    }
    else
    {
        while (aux == NULL)
        {
            pos++;
            aux = tabla[pos % NCASILLAS];
        }
        if (aux->getSig() != NULL)
        {
		while(aux->getSig()->getValor() != valor){
		    aux = aux->getSig();
		}
        }else cout << "No existe ese elemento. Verifique que está en la lista."<<endl;
    }
}

void TablaCerradaEnteros::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        cout <<" "<<"Posicion "<<i<<": ";
        while(aux != NULL){
        cout<< aux->getValor()<< " ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

int TablaCerradaEnteros::buscarLineal(int valor) {
    const int ELEMENTO_NO_ENCONTRADO{-1};
    int clave{hashlineal(valor)};

    if (this->tabla[clave]->getValor() == valor)
        return clave;

    int posiciones = clave + 1;
    if (posiciones >= NCASILLAS)
        posiciones -= NCASILLAS;

    bool haEncontradoValor{false};
    while (posiciones != clave && !haEncontradoValor) {
        if (this->tabla[posiciones] != NULL)
            haEncontradoValor = this->tabla[posiciones]->getValor() == valor;

        if (!haEncontradoValor)
            posiciones++;

        if (posiciones >= NCASILLAS)
            posiciones -= NCASILLAS;
    }

    return (haEncontradoValor) ? posiciones: ELEMENTO_NO_ENCONTRADO;
}

int TablaCerradaEnteros::hash(int valor){
    return valor % NCASILLAS;
}

//Sondeo Lineal 
int TablaCerradaEnteros::hashlineal(int pos){
	int i=1;
	
	while(tabla[pos]!=NULL){
		pos=(pos+i)%NCASILLAS;
		i++;
	}
	return pos;
}

//Cuadrático
int TablaCerradaEnteros::hashCuadratico(int pos){
    int i=0;
	int suma =0;
    int indice =0;
    suma = hash(tabla[pos]->getValor());
    indice = (pos + i*i) % NCASILLAS;
    i++;
	return indice;  
} 

//Doble hash

int TablaCerradaEnteros::hash2(int valor)
{
    int i = valor % NCASILLAS;
    int veces = 0;
    
    if(tabla[i]==NULL)
    {
    	return i;
	}
	else
	{
		function<int()> hash2 = [&]()->int
		{
			try
			{
				do{
					int dob = 7 - valor%7;
		
					i+=dob;
		
					if(i>28)
					{
						i=NCASILLAS-i;
					}
					veces++;
				}while(tabla[i]!=NULL & veces <NCASILLAS);
			
				if(veces==NCASILLAS)
				{
					throw (veces);
				}
			
				return i;
			}catch(int lleno)
			{
				cout<<"La lista esta llena."<<endl;
				system("pause");
				return -1;
			}
		};
		
		return hash2();
	}
}   

