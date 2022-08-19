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

#pragma once
#include <conio.h>
#include "Laberinto.h"
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <clocale>
#include<string>
#include <iostream>

using namespace std;

void gotoxy(short int x, short int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


Laberinto::Laberinto(int a,int b):  x(a), y(b), matriz(new int*[a]), fin(false){

	for (int i = 0;i < x; i++) 
		*(matriz + i) = new int[y];
	
	generarLaberinto();
}

void Laberinto::generarLaberinto()
{
	int j{0};
	ifstream archivo;
	string texto{"0"};

	char* a= new char[texto.length()];
	archivo.open("laberinto.txt" , ios::in);


	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	while (!archivo.eof()) {
		getline(archivo, texto);
		strcpy(a, texto.c_str());
		for (long long unsigned int i = 0; i < strlen(a); i++){
			*(*(matriz + i) + j)=*(a+i)-48;
		}
		j++;
	}

	archivo.close();
}

void Laberinto::imprimir(){
	for (int i = 0; i < y; i++){
		for (int j = 0;j < x;j++) {
			if(*(*(matriz + j) + i)==0)
				cout << (char)178;
			if (*(*(matriz + j) + i) == 1)
				cout << ' ';
			if (*(*(matriz + j) + i) == 2)
				cout << '*';
			if (*(*(matriz + j) + i) == 3)
				cout << '*';
			if (*(*(matriz + j) + i) == 4)
				cout << ' ';
		}
		cout << endl;
	}

}

bool Laberinto::buscarSolucion(int a,int b){
	do{		

		gotoxy(0, 0);
		*(*(matriz + b) + a) = 2;
		imprimir();
		if (validar(a, b) != 0) {
			switch (validar(a, b)) {
			case 1:
				fin = buscarSolucion(a - 1, b);
				break;
			case 2:
				fin = buscarSolucion(a + 1, b);
				break;
			case 3:
				fin = buscarSolucion(a, b + 1);
				break;
			case 4:
				fin = buscarSolucion(a, b - 1);
				break;
			}			
		}
		else {
			*(*(matriz + b) + a) = 4;
			break;
		}
	} while (!fin);

	return fin;
	
}

int Laberinto::validar(int a,int b)
{
	if (*(*(matriz + b - 1) + a) == 1)
		return 4;
	if (*(*(matriz + b + 1) + a) == 1)
		return 3;
	if (*(*(matriz + b) + a + 1) == 1)
		return 2;
	if (*(*(matriz + b) + a - 1) == 1)
		return 1;
	if (a == 28 || b == 113 || a == 0 || b == 0)
		return 0;
	if (*(*(matriz + b - 1) + a) == 3 || *(*(matriz + b + 1) + a) == 3 || *(*(matriz + b) + a + 1) == 3 || *(*(matriz + b) + a - 1) == 3)
		fin = true;
	return 0;
	
}
