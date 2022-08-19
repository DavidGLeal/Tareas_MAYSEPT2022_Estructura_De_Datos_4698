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
    void remove_option(long long unsigned index);
    void display();
    void stop();
    bool is_running();

private:
    std::string title;
    std::vector<MenuOption> options;
    HANDLE console;
    bool running = false;
};
