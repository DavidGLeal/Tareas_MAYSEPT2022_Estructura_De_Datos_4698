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
#include <stdlib.h>
#include <string>  

using namespace std;
    class Conversion{
        private:

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
                return stof(dato);
            }

            double numDouble(char* dato){ //Convertir a flotante 
                return stod(dato);
            }
           
    };
