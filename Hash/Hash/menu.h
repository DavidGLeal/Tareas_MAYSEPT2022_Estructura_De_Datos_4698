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
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <stdlib.h>
#include "TablaHashCerrada.cpp"
#include "TablaCerradaEnteros.cpp"
#include "TablaSondeoCuadraticoInt.cpp"
#include "TablaSondeoLinealInt.cpp"
#include "TablaHashDobleInt.cpp"
#include "TablaHashDobleText.cpp"
#include "TablaSondeoCuadraticoText.cpp"
#include "TablaSondeoLinealText.cpp"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
using namespace std;
TablaSondeoCuadraticoInt  TablaSC;
TablaSondeoLinealInt TablaSL;
TablaHashDobleInt TablaHD;
TablaSondeoCuadraticoText TablaCT;
TablaHashDobleText TablaDT;
TablaSondeoLinealText TablaLT;

int menu(const char *titulo, const char *opciones[], int n);

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string IngresoString()
{
	
	char *dato=new char[30],c;
	int i=0;
	while((c=_getch())!=13){
		if((c>=65&& c<=90)||(c>=97&&c<=122)){
			printf("%c",c);
			dato[i++]=c;}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
			i--;
		}
	}
	dato[i]='\0';
	return dato;
}

int ingresar_Datosenteros()
{
	char* dato = new char[10], c;
	int i = 0;
	printf("Ingrese un valor entero: ");
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8 || c == 127) {
			printf("\b \b");
			dato[i--] = 0;
		}
	}
	dato[i] = '\0';
	return atoi(dato);
}

void MenuIngresoLineal(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   char *cad;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar lineal (numeros)", "Insertar lineal(texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				
				int valor = ingresar_Datosenteros();
				TablaSL.insertar(valor);
				cout << "\nDato Ingresado" << endl;
				TablaSL.imprimir();
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.insertar(cadena);
					cout << "\nDato Ingresado" << endl;
					TablaLT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				cout <<"Tabla Hash"<<endl;
				TablaSL.imprimir();
				int valor = ingresar_Datosenteros();
				TablaSL.imprimir();
				TablaSL.eliminar(valor);
				cout <<"Elemento eliminado"<< endl;
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
					TablaLT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.eliminar(cadena);
					cout <<"\nElemeto eliminado"<< endl;
				system ("pause");
				break;
			}		
			case 5:{
				system("cls");
					TablaSL.imprimir();
					int valor = ingresar_Datosenteros();
					TablaSL.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					TablaLT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.buscar(cadena);
					cout<<endl;
				system ("pause");
				break;
			}							
			case 7:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuIngresoCuadratico(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar Cuadratico (numeros)", "Insertar Cuadratico(texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
					int valor = ingresar_Datosenteros();
					TablaSC.insertar(valor);
					cout << "\nDato Ingresado" << endl;		
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.insertar(cadena); //METODO INSERTAR CUADRATICO
					cout << "\nDato Ingresado" << endl;
					TablaCT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				cout << "Tabla Hash"<<endl;
				TablaSC.imprimir();
				int valor = ingresar_Datosenteros();
				TablaSC.eliminar(valor);
				cout <<"\nElemento eliminado"<< endl;
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaCT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.eliminar(cadena);
					cout<<"\nElemento eliminado"<<endl;
				system ("pause");
				break;
			}	
			case 5:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaSC.imprimir();
					int valor = ingresar_Datosenteros();
					TablaSC.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaCT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.buscar(cadena);
					cout<<endl;
				system ("pause");
				break;
			}				
			case 7:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuIngresoDoble(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar Doble (numeros)", "Insertar Doble (texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				
					int valor = ingresar_Datosenteros();
					TablaHD.insertar(valor);
					cout << "\nDato Ingresado" << endl;
					TablaHD.imprimir();
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.insertar(cadena);
					cout << "\nDato Ingresado" << endl;
					cout <<"Tabla Hash"<< endl;
					TablaDT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				TablaHD.imprimir();
				int valor = ingresar_Datosenteros();
				TablaHD.eliminar(valor);
				cout <<"\nElemento eliminado"<< endl;
				TablaHD.imprimir();
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaDT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.eliminar(cadena);
					cout<<"\nElemento eliminado"<<endl;
					cout <<"\nTabla hash cerrada"<< endl;
					TablaDT.imprimir();
				system ("pause");
				break;
			}						
			case 5:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaHD.imprimir();
					int valor = ingresar_Datosenteros();
					TablaHD.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					cout <<"Tabla Hash"<< endl;
					TablaDT.imprimir();
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.buscar(cadena);
					cout<<endl;
				system ("pause");
				break;
			}			
			case 7:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuPrincipal(){

	bool repite = true;
	int opcion;   
   
    const char *titulo = "HASH CERRADO";
    const char *opciones[] = {"Sondeo Lineal", "Sondeo Cuadratico","Doble Hash","Salir del programa"};
    int n =4;  
 
    do {
        opcion = menu(titulo, opciones, n); 	
		switch(opcion){
			case 1:{
				system("cls");
				MenuIngresoLineal();
				break;
			}
			case 2:{
				system("cls");
				MenuIngresoCuadratico();
				break;
			}		
			case 3:{
				system("cls");
				MenuIngresoDoble();
				break;
			}		
			case 4:{
				cout<<endl;
				printf("\n\n\n");
				cout<<"Saliendo del programa..."<<endl;
				repite=false;
				break;
			}										
	}
	printf("\n\n\n");
	system("pause");
	}while(repite);
}

int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  
 
   int tecla;
 
   bool repite = true; 
 
   do {
      system("cls");
      //system("Color 8B");
      gotoxy(5, 3 + opcionSeleccionada); cout << "->" << endl;
 
      
      gotoxy(15, 2); cout << titulo;
 
      
      for (int i = 0; i < n; ++i) {
         gotoxy(10, 4 + i); cout <<"["<< i + 1 << "] | " << opciones[i];
      }
 
      
 
      do {
         tecla = getch();
         
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != TECLA_ENTER);
 
      switch (tecla) {
 
         case TECLA_ARRIBA:   
 
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
 
            break;
 
         case TECLA_ABAJO:
            opcionSeleccionada++;
 
            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
 
            break;
 
         case TECLA_ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}