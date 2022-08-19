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
#pragma once
#include <stdlib.h>

    class Conversion{
        private:
            bool numero;
            int verificador = 0;

        public:
            Conversion(){} //Constructor
            ~Conversion(){} //Destructor

            int numInt(char* dato){ //Convertir a entero
                return atoi(dato); //String a int
            } 

            unsigned long numLong(char* dato){
                return atoll(dato);
            }

            float numFloat(char* dato){ //Convertir a flotante 
                return std::stof(dato);
            }

            void verificar(char c){ //Metodo para verificar flotante o entero  
                if (c == 46){ // 46 codigo ASCII del punto (.)
                    this -> numero = true; //Asigno verdadero si es un flotante, pues tiene punto
                } else{
                    this -> numero = false; //Asigno falso si es un entero. Pues no posee punto
                }
            }

            bool getNumero(){
                return this -> numero;
            }

            void setVerificador(int v){
                this -> verificador = v;
            }

            int getVerificador(){
                return this->verificador;
            }
    };