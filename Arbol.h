#pragma once
#include "Nodo.cpp"

class Arbol
{
private:
    Nodo *arbol = NULL;
    int sumaNivl{0};
    int suma{0};
    void imprimirNivelActual(Nodo *, int); //Metodo para que funcione el recorrido por nivel
public:

    int getSuma(){
        return this->suma;
    }
    void setArbol(Nodo *);
    Nodo *getArbol();
    Nodo *crearNodo(int);
    void insertarNodo(Nodo *&, int);
    void mostrar(Nodo *, int);
    void buscar(Nodo *, int);
    void buscarporNivel(Nodo *, int);
    void preOrden(Nodo *);
    void inOrden(Nodo *);
    void recorridoNivel(Nodo *);
    void postOrden(Nodo *);
    int peso(Nodo *);
    int altura(Nodo *);
    bool simetria(Nodo *, Nodo *);
    bool simetrias(Nodo *);
    Nodo *eliminarNodo(Nodo *, int);
    void sumarPorNivel(Nodo* arbol, int nivel);


};


