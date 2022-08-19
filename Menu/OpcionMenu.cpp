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

#include "OpcionMenu.h"

MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
    this->label = label;
    this->callback = callback;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->wait_after_exec = wait_after_exec;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
    this->wait_after_exec = wait_after_exec;
}

std::string MenuOption::get_label() {
    return label;
}

void MenuOption::execute() {
    callback(arguments);
}

bool MenuOption::should_wait() {
    return wait_after_exec;
}

MenuOptionArguments &MenuOption::get_args() {
    return arguments;
}