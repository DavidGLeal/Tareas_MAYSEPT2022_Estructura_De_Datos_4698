/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize los diferentes tipos de ordenamientos (internos y externos) y busquedas.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 21-06-2022
	*Fecha de modificacion:
        * 28-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/

#pragma once
#include <iostream>
#include "5ImprimirExterno.cpp"
using namespace std;
   
class MetodoExterno: public ImprimirExterno{

    private:
        string nombreArchivo{"ordenada.txt"}; //Por default
        int N{0};

        //!METODOS DE AMBAS FUNCIONES

        void abrir(fstream *f, string nom, int tip);
        void cerrar(fstream *f);

        //!ORDENACION NATURAL. METODOS INTERNOS


        void generarAleatorios(int min, int max);
        void particionInicial();
        void particionFusion();
        void limpiar();
        void intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4);

        //!ORDENACION DIRECTA. METODOS INTERNOS

        void particiona(int l);
        void fusiona(int l);


    public:
    
        MetodoExterno(string);
        ~MetodoExterno();
        MetodoExterno();
        
        //!ORDENACION DIRECTA
        void ordenarPorDirecta();
        void insertar(int d, string nom);

        //!ORDENACION NATURAL.
        void ordenarPorNatural();
        bool hayDatos();
        void limpiarArchivo();
        void insertar2(int d, string nom);
        void setN(int n);

        void imprimirInterno();

};

