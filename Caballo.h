/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  05 DE AGOSTO DE 2022
* FECHA DE Entrega: 05 DE AGOSTO DE 2022
* Version: 2
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Caballo{
    private:
        int tam;
        char** tablero;
        int mov;
        bool exito{false};
        int x{0};
        int y{0};

    public:

        Caballo(int, int);
        Caballo();

        int getX();
        int getY();

        void setX(int);
        void setY(int);

        bool validarEncuentro(Caballo& c, Caballo& c2);
        bool validarAmbos(int x1, int y1, int x2, int y2);
        bool validarFueraTablero(int x1, int y1);

        void mover(char** tablero, Caballo& c, Caballo& c2);
        void moverCaballo(Caballo& c, int, int);

        void imprimirCaballos(Caballo& c, Caballo& c2);

        void resolver();
        int validarNum(const char* msj);
};
