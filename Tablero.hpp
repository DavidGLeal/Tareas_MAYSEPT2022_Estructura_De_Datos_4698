/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  11 DE AGOSTO DE 2022
* FECHA DE Entrega: 12 DE AGOSTO DE 2022
* Version: final
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#pragma once
#include <iostream>
#include <windows.h>
#include "color.hpp"
using namespace std;

class Tablero{
    private:
        
    public:

    Tablero(){
    }
    
    ~Tablero(){
    }

    void imprimirTablero(){

        //Fila 1
        cout << "     a   b   c   d   e   f   g   h  "<<endl;
        cout << " 1  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♜", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♞", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♝", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♛", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♚", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♝", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♞", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♜", 2, nullptr, nullptr); 
        cout << "  ";
        cout << "  1 ";
        cout <<endl;

        cout << " 2  ";
        for(int i = 1; i < 9; i++){
            if (i%2 != 0){
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♟", 2, nullptr, nullptr); 
                cout << "  ";
            }else{
                cout << hue::on_bright_white; 
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♟", 2, nullptr, nullptr); 
                cout << "  ";
                cout <<hue::reset;
            }    
        }

        cout << "  2 ";
        cout <<endl;
        
        cout << " 3  ";
        for(int i = 1; i < 9; i++){
            if (i%2 != 0){
                cout << hue::on_bright_white << "    " <<hue::reset;
            }else{
                cout << "    ";
            }    
        }

        cout << "  3 ";
        cout <<endl;

        cout << " 4  ";
        for(int i = 1; i < 9; i++){
            if (i%2 == 0){
                cout << hue::on_bright_white << "    " <<hue::reset;
            }else{
                cout << "    ";
            }    
        }

        cout << "  4 ";
        cout <<endl;

        cout << " 5  ";
        for(int i = 1; i < 9; i++){
            if (i%2 != 0){
                cout << hue::on_bright_white << "    " <<hue::reset;
            }else{
                cout << "    ";
            }    
        }

        cout << "  5 ";
        cout <<endl;

        cout << " 6  ";
        for(int i = 1; i < 9; i++){
            if (i%2 == 0){
                cout << hue::on_bright_white << "    " <<hue::reset;
            }else{
                cout << "    ";
            }    
        }

        cout << "  6 ";
        cout <<endl;

        cout << " 7  ";
        for(int i = 1; i < 9; i++){
            if (i%2 == 0){
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♙", 2, nullptr, nullptr); 
                cout << "  ";
            }else{
                cout << hue::on_bright_white; 
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♙", 2, nullptr, nullptr); 
                cout << "  ";
                cout <<hue::reset;
            }    
        }

        cout << "  7 ";
        cout <<endl;

        cout << " 8  ";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♖", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♘", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♗", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♕", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♔", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♗", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♘", 2, nullptr, nullptr); 
        cout << "  ";
        cout << hue::on_bright_white; 
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L" ♖", 2, nullptr, nullptr); 
        cout << "  ";
        cout <<hue::reset;

        cout << "  8 ";
        cout <<endl;
        cout << "     a   b   c   d   e   f   g   h  "<<endl;
        cout <<endl;
    }
};