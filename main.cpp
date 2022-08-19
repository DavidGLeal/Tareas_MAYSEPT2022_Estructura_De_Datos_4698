/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  1 DE AGOSTO DE 2022
* FECHA DE Entrega: 1 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <conio.h>
#include "Laberinto.cpp"
#include <stdlib.h>
#include<iostream>
#include<Windows.h>
using namespace std;

int main() {	

	Laberinto l(100,22);
	l.imprimir();
	system("pause");

	return 0;
}
