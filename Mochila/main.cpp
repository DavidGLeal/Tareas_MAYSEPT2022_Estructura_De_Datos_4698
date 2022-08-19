/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  13 DE AGOSTO DE 2022
* FECHA DE Entrega: 14 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/


#include <iostream>
#include "Mochila.cpp"
#include "IngresoDatos.h"
using namespace std;
 
int main()
{
	IngresoDatos i;

	int cap=-1,n=-1;	
 	while(cap == -1||cap==-10101010){
            cap = i.funcionPrincipalEnteros("Ingrese la capacidad de la mochila:\n");
            
    }

    cout<<endl;
    while(n == -1||n==-10101010){
            n = i.funcionPrincipalEnteros("Ingrese el numero de objetos:\n");
    }
    cout<<endl;

    int* beneficio=new int[n];
    int* peso=new int[n];
    *beneficio=-1;
    *peso=-1;

    for(int z=0;z<n;z++){

    	*(beneficio+z)=-1;
    	*(peso+z)=-1;

	}

    for(int j=0;j<n;j++){
    	cout<<"\nObjeto "<<j+1<<" :"<<endl;
        
    	while(*(beneficio+j) == -1||*(beneficio+j)==-10101010)
    	*(beneficio+j) = i.funcionPrincipalEnteros("Ingrese el beneficio: ");    	
    	cout<<endl;   	
    	while(*(peso+j) == -1||*(peso+j)==-10101010)
    	*(peso+j) = i.funcionPrincipalEnteros("Ingrese el peso: ");
	}

	Mochila m(peso,beneficio,n,cap);
    cout << "\nBeneficio maximo de la mochila: " << m.resolver();
 
    return 0;
}