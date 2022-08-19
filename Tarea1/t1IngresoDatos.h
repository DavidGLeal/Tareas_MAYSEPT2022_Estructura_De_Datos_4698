#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

class Dato{
	private:
		 char *dato;		 
	public:
		Dato(){
			dato = new char[10];
		}

		char *ingresarDatosEnteros(char *msj);
		int convertirEntero(char *c);
		int getDoble(int num);
};
