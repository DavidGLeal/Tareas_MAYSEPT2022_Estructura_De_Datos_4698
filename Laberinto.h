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
class Laberinto{

	private:
		int x;
		int y;
		int** matriz;
		bool fin;

	public:
		Laberinto(int,int);

		void generarLaberinto();
		bool buscarSolucion(int, int);
		int validar(int,int);

		void imprimir();

};

