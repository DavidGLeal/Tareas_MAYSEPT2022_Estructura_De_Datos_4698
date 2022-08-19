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
#include "4OpcionMenu.h"

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
/**
 * @param value
 */
MenuOptionArguments &MenuOption::get_args() {
    return arguments;
}