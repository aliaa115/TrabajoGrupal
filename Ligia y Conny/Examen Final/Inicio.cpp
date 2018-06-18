#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Lista_Simple.h"
#include <string>

int main() {
	std::string eleccionmenu;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n\t\tPROYECTO CON GITHUB Y HITKRAKEN PARA EXAMEN FINAL DE PROGRAMACION 3:\n\tElija uno de los temas a continuacion para ejecutar el programa:\n"
		"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\tEleccion:  ", 
		"\t\t 01 - pilas", 
		"\t\t 02 - colas",
		"\t\t 03 - listas simples", 
		"\t\t 04 - listas dobles", 
		"\t\t 05 - listas circulares",
		"\t\t 06 - tablas hash ( numericas )", 
		"\t\t 07 - tablas hash ( descriptivas )", 
		"\t\t 08 - floyd", 
		"\t\t 09 - ", 
		"\t\t 10 - ", 
		"\t\t 00 - SALIR");
	std::cin >> eleccionmenu;
	menu(eleccionmenu);
	while (eleccionmenu != "0") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("cls");
		printf("\n\t\tPROYECTO CON GITHUB Y HITKRAKEN PARA EXAMEN FINAL DE PROGRAMACION 3:\n\tElija uno de los temas a continuacion para ejecutar el programa:\n"
			"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\tEleccion:  ",
			"\t\t 01 - pilas",
			"\t\t 02 - colas",
			"\t\t 03 - listas simples",
			"\t\t 04 - listas dobles",
			"\t\t 05 - listas circulares",
			"\t\t 06 - tablas hash ( numericas )",
			"\t\t 07 - tablas hash ( descriptivas )",
			"\t\t 08 - floyd",
			"\t\t 09 - ",
			"\t\t 10 - ",
			"\t\t 00 - SALIR"); 
		std::cin >> eleccionmenu;
		menu(eleccionmenu);
	}
	_getch();
}