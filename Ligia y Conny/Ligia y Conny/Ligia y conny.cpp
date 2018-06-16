#include <iostream>
#include <conio.h>
#include "Menu.h"

using namespace std;
//pilas,colas,listas simple,listas dobles,listas circulares
//tablas hash con numeros,tablas hash con letras,

///---------PROTOTIPOS---------


///=======FUNCION MAIN=======

void main() {
	cout << "\t\tPROYECTO CON GITHUB Y HITKRAKEN DE PROGRAMACION 3\n\n";
	cout << "\tEl siguiente programa contiene los siguientes temas:\n"; 
	cout << "\t\t 01 - pilas\n";
	cout << "\t\t 02 - colas\n";
	cout << "\t\t 03 - listas simples\n";
	cout << "\t\t 04 - listas dobles\n";
	cout << "\t\t 05 - listas circulares\n";
	cout << "\t\t 06 - tablas hash ( numericas )\n";
	cout << "\t\t 07 - tablas hash ( descriptivas )\n";
	cout << "\t\t 08 - \n";
	cout << "\t\t 09 - \n";
	cout << "\t\t 10 - \n";
	cout << "\t\t 00 - SALIR\n";
	cout << "\t\t\tINGRESE EL PROGRAMA A EJECUTAR:  "; menu(_getch());
}