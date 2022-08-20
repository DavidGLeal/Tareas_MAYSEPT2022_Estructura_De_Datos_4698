#pragma once
#include "nodo.h"
#include <functional>
#include <iostream>

template<typename T>
class ListaEnlazada {
public:
    // constructor por defecto
    ListaEnlazada() = default;

    /*
     * Inserta un elemento al final de la lista
     */
    void insertar(T valor);

    /*
     * Inserta un elemento al inicio de la lista
     */
    void insertarInicio(T valor);

    /*
     * Inserta un elemento a la lista en un indice especifico,
     * una vez encontrado el indice, se puede especificar a que lado del elemento
     * encontrado se insertara el nuevo elemento (por defecto: derecha)
     */
    void insertarEn(int indice, T valor, Direccion = Direccion::Derecha);

    /*
     * Elimina un elemento de la lista dado un indice especifico
     */
    void eliminarEn(int indice);

    /*
     * Elimina los elementos de la lista que cumplan con el criterio
     * del parametro funcion 'filtro', si la funcion 'filtro' es una
     * funcion que retorna TRUE entonces el elemento es eliminado.
     */
    void eliminar(std::function<bool(T valor)> filtro);

    /*
     * Transforma todos los valores de la lista a un valor especifico
     * que devuelva la funcion anonima 'conversor'
     */
    void transformar(std::function<T(T valor)> conversor);

    /*
     * obtiene el ultimo nodo de la lista
     */
    Nodo<T>* obtenerUltimo();

    /*
     * obtiene un nodo de la lista en un indice especifico
     */
    Nodo<T>* obtenerEn(int indice);

    /*
     * Realiza una busqueda lineal en la lista, en cada iteracion
     * se llama al argumento 'filtro' el cual es una funcion anonima
     * en caso de que esta funcion regrese verdadero, entonces regresamos
     * el ultimo nodo recorrido, en caso de que nunca regrese verdadero,
     * se regresa un puntero nulo
     */
    Nodo<T>* buscar(std::function<bool(T valor)> filtro);

    /*
     * Recorre la lista elemento a elemento desde el inicio (cabeza)
     * cada iteración o ciclo ejecuta el argumento 'llamada', el cual
     * es una función anonima que recibe un parametro el cual es el
     * valor de cada nodo recorrido.
     */
    void recorrer(std::function<void(T valor)> llamada);

    /*
     * Regresa verdadero si tamanio_ tiene un valor de 0
     */
    bool vacio();

    /*
     * Retorna el tamaño de la lista
     */
    int tamanio();

private:
    Nodo<T>* cabeza_ = nullptr;
    int tamanio_ = 0;
};

template<typename T>
void ListaEnlazada<T>::insertar(T valor)
{
    Nodo<T>* nodo = new Nodo<T>(valor);
    Nodo<T>* ultimo = obtenerUltimo();

    // si la cabeza es nula, la lista esta vacia
    // entonces definimos la cabeza como nuevo nodo
    if (ultimo == nullptr) {
        cabeza_ = nodo;
    } else {
        // agregamos el nodo a la lista enlazada
        ultimo->siguiente(nodo);
    }

    // la lista agrego un elemento, incrementamos el tamaño
    tamanio_++;
}

template<typename T>
void ListaEnlazada<T>::insertarInicio(T valor)
{
    Nodo<T>* nodo = new Nodo<T>(valor);

    // para insertar en el inicio, necesitamos la cabeza de la lista
    // si esta vacia solo insertamos el elemento sin mas
    if (vacio()) {
        insertar(valor);
        return;
    }

    // creamos un temporal de la cabeza de la lista
    Nodo<T>* temporal = cabeza_;

    // el nuevo nodo apunta a la cabeza
    nodo->siguiente(cabeza_);

    // ahora el nuevo nodo es la cabeza
    cabeza_ = nodo;
}

template<typename T>
void ListaEnlazada<T>::insertarEn(int indice, T valor, Direccion direccion)
{
    // verificamos que el indice exista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;

        return;
    }

    // si existe un solo nodo la insercion es al inicio o al final
    if (tamanio_ == 1) {
        if (direccion == Direccion::Izquierda) {
            insertarInicio(valor);
        } else {
            insertar(valor);
        }

    // si el indice es 0 y la insercion es hacia la izquierda,
    // entonces insertamos al inicio
    } else if (indice == 0 && direccion == Direccion::Izquierda) {
        insertarInicio(valor);

    // si el indice es el ultimo elemento y la insercion es 
    // hacia a la derecha, entonces solo insertamos al final
    } else if (indice == tamanio_ - 1 && direccion == Direccion::Derecha) {
        insertar(valor);

    // insertamos en el indice deseado en la direccion deseada
    } else {
        Nodo<T>* anterior = (indice - 1 < 0 ? nullptr : obtenerEn(indice - 1));
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* siguiente = objetivo->siguiente();
        Nodo<T>* nodo = new Nodo<T>(valor);

        if (direccion == Direccion::Derecha) {
            objetivo->siguiente(nodo);
            nodo->siguiente(siguiente);
        } else {
            anterior->siguiente(nodo);
            nodo->siguiente(objetivo);
        }

        tamanio_++;
    }
}

template<typename T>
void ListaEnlazada<T>::eliminarEn(int indice)
{
    // verificamos que el indice exista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;

        return;
    }

    if (tamanio_ == 1) {
        delete cabeza_;
        cabeza_ = nullptr;
    } else if (indice == tamanio_ - 1) {
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* penultimo = obtenerEn(indice - 1);

        delete objetivo;
        penultimo->siguiente(nullptr);
    } else {
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* anterior = obtenerEn(indice - 1);
        Nodo<T>* siguiente = objetivo->siguiente();

        delete objetivo;
        anterior->siguiente(siguiente);
    }

    tamanio_--;
}

template<typename T>
void ListaEnlazada<T>::eliminar(std::function<bool(T valor)> filtro)
{
    Nodo<T>* nodo = cabeza_;
    int indice = 0;

    while (nodo != nullptr) {
        bool eliminar = filtro(nodo->valor());

        if (eliminar) {
            eliminarEn(indice);
            return;
        }

        nodo = nodo->siguiente();
        indice++;
    }
}

template<typename T>
inline void ListaEnlazada<T>::transformar(std::function<T(T valor)> conversor)
{
    Nodo<T>* nodo = cabeza_;

    while (nodo != nullptr) {
        T nuevoValor = conversor(nodo->valor());
        nodo->valor(nuevoValor);
        nodo = nodo->siguiente();
    }
}

template<typename T>
Nodo<T>* ListaEnlazada<T>::obtenerUltimo()
{
    Nodo<T>* ultimo = cabeza_;

    if (ultimo == nullptr) {
        return nullptr;
    }

    // recorremos todos los nodos hasta llegar al ultimo
    while (ultimo != nullptr && ultimo->siguiente() != nullptr) {
        ultimo = ultimo->siguiente();
    }

    // retornamos el ultimo nodo encontrado
    return ultimo;
}

template<typename T>
Nodo<T>* ListaEnlazada<T>::obtenerEn(int indice)
{
    // verificamos que el indice exista en la lista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;
        return nullptr;
    }

    int i = 0; // indice
    Nodo<T>* nodo = cabeza_; // primer elemento

    // recorremos la lista entera hasta encontrar el elemento
    // que tenga el indice deseado
    while (nodo != nullptr) {
        if (i++ == indice) {
            return nodo;
        }

        nodo = nodo->siguiente();
    }

    return nullptr;
}

template<typename T>
Nodo<T>* ListaEnlazada<T>::buscar(std::function<bool(T valor)> filtro)
{
    for (Nodo<T>* nodo = cabeza_; nodo != nullptr; nodo = nodo->siguiente()) {
        bool encontrado = filtro(nodo->valor());

        if (encontrado) {
            return nodo;
        }
    }

    return nullptr;
}

template<typename T>
void ListaEnlazada<T>::recorrer(std::function<void(T valor)> llamada)
{
    for (Nodo<T>* nodo = cabeza_; nodo != nullptr; nodo = nodo->siguiente()) {
        llamada(nodo->valor());
    }
}

template<typename T>
bool ListaEnlazada<T>::vacio()
{
    return tamanio_ == 0;
}

template<typename T>
int ListaEnlazada<T>::tamanio()
{
    return tamanio_;;
}
