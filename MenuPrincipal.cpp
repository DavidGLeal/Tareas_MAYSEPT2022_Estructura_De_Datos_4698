#pragma once
#include "MenuPrincipal.hpp"
#include "Input.cpp"
#include "HandleConsole.cpp"
#include "MenuImprimir.cpp"
#include <iostream>

bool MenuPrincipal::determinarOpcion(size_t opcionSeleccionada) {
    this->arbol.setArbol(this->raiz);
    MenuImprimir submenuImprimir(this->arbol);
    switch (opcionSeleccionada) {
        case 1:
            agregar();
            break;

        case 2:
            eliminar();
            break;

        case 3:
            buscar();
            break;
        
        case 4:
            submenuImprimir.start();
            break;

        case 5:
            return true;
            break;
    }

    std::cout << std::endl;
    system("pause");
    return false;
}

void MenuPrincipal::agregar() {
    std::cout << "Ingrese un numero entero a guardar en: ";
    int valor = Input::integerNumber(1, 4);

    this->arbol.insertarNodo(this->raiz, valor);
}

void MenuPrincipal::eliminar() {
    std::cout << "Ingrese un numero entero a eliminar: ";
    int valor = Input::integerNumber(1, 4);

    this->arbol.eliminarNodo(this->raiz, valor);
}

void MenuPrincipal::buscar() {
    std::cout << "Ingrese un numero entero a buscar en el arbol: ";
    int valor = Input::integerNumber(1, 4);

    this->arbol.buscar(this->raiz, valor);
}

MenuPrincipal::MenuPrincipal() {
    this->arbol.setArbol(this->raiz);
    this->menuPrincipal.setTitleMenu("MENU PRINCIPAL");
    this->menuPrincipal.setListOptions(
        new std::string[this->cantidadDeOpciones]{
            "Ingresar",
            "Eliminar",
            "Buscar",
            "Imprimir",
            "Salir"
        },
        this->cantidadDeOpciones
    );
    this->menuPrincipal.setPositionOfMenu(this->ubicacion);
}

void MenuPrincipal::start() {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menuPrincipal.print());
    }
}