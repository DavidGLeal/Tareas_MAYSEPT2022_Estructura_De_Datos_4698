#pragma once

enum class Direccion {
    Izquierda,
    Derecha
};

template <typename T>
class Nodo {
public:
    Nodo(T valor);

    T valor();
    void valor(T valor);
    
    Nodo<T>* siguiente();
    void siguiente(Nodo<T>* siguiente);

    Nodo<T>* anterior();
    void anterior(Nodo<T>* anterior);

private:
    T valor_;
    Nodo<T>* siguiente_ = nullptr;
    Nodo<T>* anterior_ = nullptr;
};

template<typename T>
Nodo<T>::Nodo(T valor)
{
    valor_ = valor;
}

template<typename T>
T Nodo<T>::valor()
{
    return valor_;
}

template<typename T>
void Nodo<T>::valor(T valor)
{
    valor_ = valor;
}

template<typename T>
Nodo<T>* Nodo<T>::siguiente()
{
    return siguiente_;
}

template<typename T>
void Nodo<T>::siguiente(Nodo<T>* siguiente)
{
    siguiente_ = siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::anterior()
{
    return anterior_;
}

template<typename T>
void Nodo<T>::anterior(Nodo<T>* anterior)
{
    anterior_ = anterior;
}
