#ifndef MENU_IMPRIMIR_HPP
#define MENU_IMPRIMIR_HPP
#include "MenuGUI.cpp"
#include "Arbol.cpp"

class MenuImprimir {
    private:
        Arbol arbolAImprimir;
        const size_t cantidadDeOpciones{6};
        COORD ubicacion{12, 5};
        MenuGUI menuImprimir;

        bool determinarOpcion(int opcionSeleccionada);
        void impresionPreOrden();
        void impresionInOrden();
        void impresionPosOrden();
        void impresionAmplitud();
        void impresionModoGrafico();

    public:
        MenuImprimir(Arbol arbol);
        void start();
};

#endif