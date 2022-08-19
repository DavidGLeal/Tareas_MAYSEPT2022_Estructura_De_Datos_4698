#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

//NODO
struct Nodo{
	int dato;
	Nodo *siguiente;
};


int main() {
  int opcion = 0;
	Nodo *lista = NULL;
  do {
    printf("\n\t\tMENU PRINCIPAL\n");
    printf("\t1.-Introducir un elemento a la Lista\n");
    printf("\t2.-Imprimir elementos\n");
    printf("\t3.-Eliminar por cabeza\n");
    printf("\t3.-Eliminar por cabeza\n");
    printf("\t4.-Eliminar por cola\n");
    printf("\t5.-Sumar todos los elementos de la lista\n");
    printf("\t6.-Buscar primera instancia\n");
    printf("\t7.-Buscar última instancia\n");
    printf("\t8.-Salir\n");
    printf("\tIngrese una opción: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
      // llamada a la clase
      system("clear");
      printf("\tIntroducir un elemento a la Lista\n");
      system("pause");
      break;

    case 2:
      // llamada a la clase
      system("clear");
      printf("\tImprimir elementos\n");
      system("pause");
      break;

    case 3:
      // llamada a la clase
      system("clear");
      printf("\tEliminar por cabeza\n");
      system("pause");
      break;

    case 4:
      // llamada a la clase
      system("clear");
      printf("\tEliminar por cola\n");
      system("pause");
      break;

    case 5:
      // llamada a la clase

      system("clear");
      printf("\tSumar todos los elementos de la lista\n");
      system("pause");
      break;
    case 6:
      // llamada a la clase Suma
      system("clear");
      printf("\tBuscar primera instancia\n");
      system("pause");
      break;
    case 7:
      // llamada a la clase
      system("clear");
      printf("\tBuscar por última instancia\n");
      system("pause");
      break;

    default:
      cout << "Salio con exito!!!!." << endl;
      system("pause");
      break;
    }
  } while (opcion != 8);
}
