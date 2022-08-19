#ifndef RELOJ_H
#define RELOJ_H

#include <iostream>
#include <iomanip>
using namespace std;

class Reloj
{    
    private:
        int hora;
        int minuto;
        int segundo;

   public:
        Reloj(int h=0, int m=0, int s=0);
        void DefineTiempo(int, int, int);
        void DefineHora(int);
        void DefineMinuto(int);
        void DefineSegundo(int);
        int Hora(void);
        int Minuto(void);
        int Segundo(void);
        void operator ++ (void);
};

#endif 