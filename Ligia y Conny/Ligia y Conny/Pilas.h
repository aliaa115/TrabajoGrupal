#define CRT_NO_WARNING_SECURITY
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cstdio>

using namespace std;

struct pila {
	int num;
	struct pila *sP;
}*inicio = NULL, *final = NULL;

int op = 0, opP = 0;

void visualizarP() {
	if (final == NULL) {
		system("cls");
		cout << "NO HAY ELEMENTOS A LISTAR...";
	}
	else {
		system("cls");
		cout << "ELEMENTOS INSERTADOS EN LA PILA\n\n";
		inicio = final;
		while (inicio != NULL) {
			cout << "Numero: " << inicio->num << "\n";
			inicio = inicio->sP;
		}
	}
	_getch();
}

void menu1() {
	system("cls");
	cout << "			MENU 		\n";
	cout << "	1. Pila				\n";
	cout << "	2. Salir			\n";
	cout << "	Ingrese una opcion: ";
}


void insertarP() {
	inicio = new pila;
	system("cls");
	cout << "Ingrese un numero entero: ";
	cin >> inicio->num;
	if (final == NULL) {
		final = inicio;
		inicio->sP = NULL;
	}
	else {
		inicio->sP = final;
		final = inicio;
	}
}


void extraerP() {
	if (final == NULL) {
		system("cls");
		cout << "NO HAY ELEMENTOS A ELIMINAR...";
	}
	else {
		inicio = final;
		system("cls");
		cout << "FUNCION ELIMINAR ELEMNTOS DE LA PILA\n\n";
		cout << "El dato a eliminar es: " << inicio->num;
		_getch();
		final = final->sP;
		delete inicio;
	}
}


void menup() {
	system("cls");
	cout << "			MENU PILA		\n";
	cout << "\nMANEJO DE UNA ESTRUCTURA TIPO PILA\n";
	cout << "	1. Insertar				\n";
	cout << "	2. Visualizar			\n";
	cout << "	3. Extraer				\n";
	cout << "	4. Salir				\n";
	cout << "	Ingrese una opcion: ";
	cin >> opP;
	switch (opP) {
	case 1:
		insertarP();
		break;
	case 2:
		visualizarP();
		break;
	case 3:
		extraerP();
	case 4:
		exit(0);
		break;
	default:
		break;
	}while (opP != 4);
}

int main2() {
	system("cls");
	do {
		menu1();
		cin >> op;
		switch (op) {
		case 1: {
			system("cls");
			cout << "\t\tPILA\n\n";
			menup();
			cin >> opP;
			_getch();
		}
		default:
			cout << "OPCION NO VALIDA...";
			_getch();
			break;
		}
	} while (op != 2);
	_getch();
	return 0;
}
