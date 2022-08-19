/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  9 DE AGOSTO DE 2022
* FECHA DE Entrega: 10 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include "Menu.h"
#include <conio.h>

Menu::Menu() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}

Menu::Menu(std::string title) {
    this->title = title;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Menu::add_option(MenuOption option) {
    options.push_back(option);
}

void Menu::remove_option(int index) {
    if (index < 0 || index > options.size()) {
        return;
    }

    std::vector<MenuOption>::iterator it = options.begin();
    std::advance(it, index);
    options.erase(it);
}

void Menu::display() {
    int selected = 1;

    if (options.empty()) {
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD csbi_defaults;

    GetConsoleScreenBufferInfo(console, &csbi);
    csbi_defaults = csbi.wAttributes;

    running = true;

    while (running) {
        int position = 1;
        
        system("cls");

        std::cout << title << std::endl << std::endl;

        for (MenuOption option : options) {
            if (option.get_args().has("__index")) {
                option.get_args().set("__index", position - 1);
            } else {
                option.get_args().add("__index", position - 1);
            }

            if (position++ == selected) {
                SetConsoleTextAttribute (console, BACKGROUND_BLUE);
            }

            std::cout << option.get_label() << std::endl;
            SetConsoleTextAttribute (console, csbi_defaults);
        }

        int key;

        do {
#ifdef _MSC_VER
            key = _getch();

            if (key == 0) {
                key = _getch();
            }
#else
            key = getch();

            if (key == 0) {
                key = getch();
            }
#endif
        } while (key != ARRIBA && key != ABAJO && key != ENTER);
        
        switch (key) {
            case ARRIBA: {
                selected--;

                if (selected < 1) {
                    selected = options.size();
                }
            }
            break;
            case ABAJO: {
                selected++;

                if (selected > options.size()) {
                    selected = 1;
                }
            }
            break;
            case ENTER: {
                MenuOption option = options.at(selected - 1);
                std::cout << std::endl << std::endl;
                option.execute();

                if (option.should_wait()) {
                    std::cout << std::endl << std::endl;
                    system("pause");
                }
            }
        }
    }
}

void Menu::stop() {
    running = false;
}

bool Menu::is_running() {
    return running;
}