#pragma once
#include <iostream>
#include "TablaCerradaEnteros.h"
#include "NodoEntero.h"
#include "NodoEntero.cpp"

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
void TablaCerradaEnteros::insertar(int valor){
    int pos = hash(valor);
    
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircularEntero(valor);
    }
    else{
        while(tabla[pos]!=NULL)
        {
        	pos=hash2(pos);
		}
    	tabla[pos] = new NodoCircularEntero(valor);
	}
}
void TablaCerradaEnteros::eliminar(int valor){
    int pos = hash(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos]==NULL){
        cout<<"Lista Vacia"<<endl;
    }else{
        if(aux->getValor() == valor){
            tabla[pos] = tabla[pos]->getSig();
            delete aux;
        }
        else{
            while(tabla[pos]->getValor()!=valor)
            {
                pos=hash2(pos);
            }
            aux = tabla[pos];
            tabla[pos] = tabla[pos]->getSig();
            delete aux;
            
        }
    }
}
void TablaCerradaEnteros::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        while(aux != NULL){
            cout <<"Posicion["<<i<<"]: "<< aux->getValor() << " ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

void TablaCerradaEnteros::buscar(int valor) {
    const int ELEMENTO_NO_ENCONTRADO{-1};
    int clave{hash(valor)};
	int retorno = clave;
	bool noEsta=false;
	if(tabla[clave]==NULL|| tabla[clave]->getValor()!=valor)
	{
		clave+=hash2(valor);
		while(tabla[clave]==NULL||tabla[clave]->getValor()!=valor || clave!=retorno)
		{
			clave=hash2(valor);
            if(clave==retorno)
		    {
			noEsta=true;
            break;
		    }
		}       
	}
	if(!noEsta)
	{
		cout<<"\nPosicion["<<clave<<"]: "<<tabla[clave]->getValor()<<endl;
    
    	cout<<"Elemento encontrado!\n"<<endl;
	}
	else 
	{   
		cout<<"\nEl elemento no se encuentra en la lista"<<endl;
	}     
}

int TablaCerradaEnteros::hash(int valor){
    return valor % NCASILLAS;
}


