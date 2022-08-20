#pragma once
#include <iostream>
#include <string>
#include "HashAbierto.h"
#define NUM_CELDAS 30

HashAbierto::HashAbierto()
{
    tablaHash = new NodoCircular*[NUM_CELDAS];
    for (int i = 0; i < NUM_CELDAS; i++)
    {
        tablaHash[i] = NULL;
    }
}
HashAbierto::~HashAbierto()
{
    for (int i = 0; i < NUM_CELDAS; i++)
    {
        NodoCircular* aux = tablaHash[i];
        aux = tablaHash[i];
        while (aux != NULL)
        {
            tablaHash[i] = tablaHash[i]->getSiguiente();
            delete (aux);
            aux = tablaHash[i];
        }
    }
    delete [] tablaHash;
}
int HashAbierto::hash(std::string _dato)
{
    int suma = 0;
    for (int i = 0; i < _dato.length(); i++)
    {
        suma += _dato[i];
    }
    return suma % NUM_CELDAS;
}
int HashAbierto::hashEntero(int _dato)
{
    return _dato % NUM_CELDAS;
}
void HashAbierto::insertarDatoEntero(int _dato)
{
    int pos = hashEntero(_dato);
    NodoCircular *aux = tablaHash[pos];
    if (tablaHash[pos] == NULL)
    {
        tablaHash[pos] = new NodoCircular(std::to_string(_dato));
    }
    else
    {
        aux = tablaHash[pos];
        while (aux->getSiguiente() != NULL)
        {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(new NodoCircular(std::to_string(_dato)));
    }
}
void HashAbierto::insertarDato(std::string _dato)
{
    int pos = hash(_dato);
    NodoCircular *aux = tablaHash[pos];
    if (tablaHash[pos] == NULL)
    {
        tablaHash[pos] = new NodoCircular(_dato);
    }
    else
    {
        aux = tablaHash[pos];
        while (aux->getSiguiente() != NULL)
        {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(new NodoCircular(_dato));
    }
}
void HashAbierto::buscarDatoEntero(int _dato)
{
    int pos = hashEntero(_dato);
    NodoCircular *aux = tablaHash[pos];
    if (aux->getDato() == std::to_string(_dato))
    {
        std::cout << "Su elemento está en la posición N°: " << pos;
        tablaHash[pos] = tablaHash[pos]->getSiguiente();
    }
    else
    {
        std::cout << "Su elemento no está en esta tabla.";
    }
}
void HashAbierto::buscarDato(std::string _dato)
{
    int pos = hash(_dato);
    NodoCircular *aux = tablaHash[pos];
    if (aux->getDato() == _dato)
    {
        std::cout << "Su elemento está en la posición N°: " << pos;
        tablaHash[pos] = tablaHash[pos]->getSiguiente();
    }
    else
    {
        std::cout << "Su elemento no está en esta tabla.";
    }
}
void HashAbierto::eliminarDatoEntero(std::string _dato)
{
    int pos = hashEntero(stoi(_dato));
    NodoCircular *aux = tablaHash[pos];
    if (aux->getDato() == _dato)
    {
        std::cout << "Eliminando el elemento de la Posicion..." << pos<<std::endl;
        delete (tablaHash[pos]);
        tablaHash[pos] = tablaHash[pos]->getSiguiente();
    }
    else
    {
        std::cout << "Elemento no encontrado";
    }
}
void HashAbierto::eliminarDatoString(std::string _dato)
{
    int pos = hash(_dato);
    NodoCircular *aux = tablaHash[pos];
    if (aux->getDato() == _dato)
    {
        std::cout << "Eliminado el elemento..." << pos;
        delete (tablaHash[pos]);
        tablaHash[pos] = tablaHash[pos]->getSiguiente();
    }
    else
    {
        std::cout << "Elemento no encontrado";
    }
}
void HashAbierto::imprimir()
{
    for (int i = 0; i < NUM_CELDAS; i++)
    {
        NodoCircular *aux = tablaHash[i];
        aux = tablaHash[i];
        while (aux != nullptr)
        {
            std::cout << "["<< i << "]  " << aux->getDato() << " ";
            aux = aux->getSiguiente();
        }
        std::cout << std::endl;
    }
}