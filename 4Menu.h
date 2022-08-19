/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#pragma once
#include "4OpcionMenu.h"
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
/**
* Menu implementation
*/


public:
    /**
    * @param key
    * @param argument
    * @return void add
    */
    Menu();
    Menu(std::string title);
        /**
    * @param key
    * @param argument
    * @return void add
    */
    void add_option(MenuOption option);
    /**
    * @param key
    * @param value
    * @return void add
    */
    void remove_option(long long unsigned int);

    /**
    * @param key
    * @return T get
    */
    void display();

    /**
    * @param key
    * @param value
    * @return void set
    */
    void stop();
    /**
    * @param key
    * @return has
    */
    bool is_running();

private:
    std::string title;
    std::vector<MenuOption> options;
    HANDLE console;
    bool running = false;
};
