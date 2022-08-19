#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    public:
        static void setCursorPosition(SHORT x, SHORT y);
        static void setCursorVisibilitie(bool isEnabled);
};

#endif