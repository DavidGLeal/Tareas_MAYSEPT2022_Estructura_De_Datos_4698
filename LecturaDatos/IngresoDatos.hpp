/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  13 DE AGOSTO DE 2022
* FECHA DE Entrega: 14 DE AGOSTO DE 2022
* Version: final
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#pragma once
#include <conio.h>
#include <string>
#include "Conversion.h"
#include <regex>
#include <iostream>
using namespace std;


    /* Creando una clase llamada IngresoDatos. */
    class IngresoDatos{
        private:

            char* dato; //Arreglo donde guardare la insercion de mis numeros
            Conversion conversion; //Instancia de conversion para determinar y transformar enteros y flotantes
            bool estaVacio;
            bool esInvalido;
            
            void imprimirMensaje(string str){
                cout<< str <<endl;
            }

            void lecturaDatos(){
                cin >> dato;
            }

        public:

           /**
            * *|Constructor|*
            */

            IngresoDatos(): dato(new char[100]){
            }    

            /**
             * El destructor se llama cuando el objeto es destruido.
             */
            ~IngresoDatos(){
                delete [] dato; //Lo libero
            }   

            bool vacio(){
                return this->estaVacio;
            }

            bool invalido(){
                return this->esInvalido;
            }

            int ingresarEntero(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoEntero(dato)){
                    return this -> conversion.numInt(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }

            int ingresarEnteroSinSigno(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoEnteroSinSigno(dato)){
                    return this -> conversion.numInt(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }

            float ingresarFlotante(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoDecimal(dato)){
                    return this -> conversion.numFloat(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }

            float ingresarFlotanteSinSigno(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoDecimalSinSigno(dato)){
                    return this -> conversion.numFloat(dato);
                }else{
                    esInvalido = true;
                }

                return -1;
            }

            double ingresarDouble(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoDecimal(dato)){
                    return this -> conversion.numDouble(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }

            double ingresarDoubleSinSigno(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoDecimalSinSigno(dato)){
                    return this -> conversion.numDouble(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }

            string ingresarTexto(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoTexto(dato)){
                    return this -> dato;
                }else{
                    esInvalido = true;
                }

                return "0";

            }
            
            bool esValidoDecimal(char* dato){
                const regex r("^[-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$");
                return regex_match(dato,r);
            }

            bool esValidoEntero(char* dato){
                const regex r("^[-]?([0-9]+([0-9]*)?|[0-9]+)$");
                return regex_match(dato,r);
            }

            bool esValidoEnteroSinSigno(char* dato){
                const regex r("^([0-9]+([0-9]*)?|[0-9]+)$");
                return regex_match(dato,r);
            }
            
            bool esValidoDecimalSinSigno(char* dato){
                const regex r("^([0-9]+([.][0-9]*)?|[.][0-9]+)$");
                return regex_match(dato,r);
            }


            bool esValidoTexto(char* dato){
                const regex r("^[a-zA-Z\\s]*$");
                return regex_match(dato,r);
            }
            
            //Para clase moneda

            float leerDinero(){

                lecturaDatos();
                estaVacio = false;
                esInvalido =  false;

                if(dato[0] == '\0'){
                    estaVacio = true;    
                }else if(esValidoDecimalSinSigno(dato) || esValidoEnteroSinSigno(dato)){
                    return this -> conversion.numFloat(dato);
                }else{
                    esInvalido = true;
                }

                return -1;

            }
};

