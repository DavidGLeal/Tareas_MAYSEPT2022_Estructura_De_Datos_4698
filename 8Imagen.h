#include <iostream>
#include <graphics.h>
#include <windows.h>

int main()
{
	initwindow(700, 600, "Grupo 2", 300, 300);
	//setviewport(0,0,800,200,1);
	setbkcolor(COLOR(170,223,101));
	clearviewport();
	readimagefile("Grupo2.jpg",100, 20, 600, 580);
	getch();
	return 0;
}