#ifndef AT3GLOBAL_H
#define AT3GLOBAL_H

#include "t3IngresoDatos.cpp"

class Global{

    private: 
        IngresoDatos ingreso;
        char *dato;

    public:
    
        Global(char *dato);
        char *getString(int size);

        char *leerDatos(char *dato);
        void imprimirMensaje(char *str);

        void imprimirNumero();
};


#endif 