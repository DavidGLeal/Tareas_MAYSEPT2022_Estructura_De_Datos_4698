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
#include <algorithm> 

#pragma once
class Mochila{
	private:
		int  nElementos;
		int* peso;
		int* beneficio;
		int  capacidad;
	public:
		Mochila();
		Mochila(int*,int*,int,int);
		int capacidadMaxima(int*,int*,int,int);
		int resolver();	
};