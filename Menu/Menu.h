/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  9 DE AGOSTO DE 2022
* FECHA DE Entrega: 10 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#pragma once
#include "OpcionMenu.h"
#include <iostream>
#include <vector>
#include <windows.h>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 77
#define DERECHA 75
#define ENTER 13
#define ESCAPE 27

class Menu {
public:
    Menu();
    Menu(std::string title);
    void add_option(MenuOption option);
    void remove_option(int index);
    void display();
    void stop();
    bool is_running();

private:
    std::string title;
    std::vector<MenuOption> options;
    HANDLE console;
    bool running = false;
};
