#include <iostream>
#include <string>
#include "lista_enlazada.h"
#include "Operaciones.h"
#include "utilidades.h"

int main(int argc, char** argv) {
	ListaEnlazada<int> lista;
	ListaEnlazada<int> listaMcm;
	Operaciones ops;
	char opcion;
	
	do {
		std::string input = leerCadenaNumerica("Ingrese un numero: ");
		int n = convertirEnEntero(input);
		
		lista.insertar(n);
		
		do {
			std::cout << "\n\nDeseas ingresar otro numero? (S/N): ";
			std::cin >> opcion;
			opcion = tolower(opcion);
		} while (opcion != 's' && opcion != 'n');
		
	} while (opcion == 's');
	
	int posicion = 0;
	int n2;
	
	lista.recorrer([&](int n) {
		posicion++;
		
		std::cout << n << std::endl;
		
		if (posicion % 2 == 0) {
			int mcm = ops.MinimoComunMultiplo(n, n2);
			std::cout << "   (MCM: " << mcm << ")" << std::endl;
			listaMcm.insertar(mcm);
		} else if (posicion == lista.tamanio()) {
			std::cout << "   (MCM: " << n << ")" << std::endl;
			listaMcm.insertar(n);
		}
		
		n2 = n;
	});
	
	std::cout << std::endl << std::endl;
	std::cout << "Lista de maximos comun multiplos: ";
	
	listaMcm.recorrer([](int n) {
		std::cout << n << "  ";
	});
	
	std::cout << std::endl;
	
	return 0;
}