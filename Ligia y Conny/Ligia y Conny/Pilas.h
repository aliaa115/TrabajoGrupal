#pragma once 
#define CRT_NO_WARNING_SECURITY
#include <iostream>
#include<conio.h>


using namespace std;

struct pila {
	int num;
	struct pila *sP;
}*inicio = NULL, *final = NULL;

int op1 = 0, op1P = 0;

void insertarP();
void extraerP();
void visualizarP();
void menup();

void menup() {
	system("cls");
	cout << "			MENU PILA		\n";
	cout << "\nMANEJO DE UNA ESTRUCTURA TIPO PILA\n";
	cout << "	1. Insertar				\n";
	cout << "	2. Visualizar			\n";
	cout << "	3. Extraer				\n";
	cout << "	4. Salir				\n";
	cout << "	Ingrese una op1cion: ";
	cin >> op1P;
	switch (op1P) {
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
	}while (op1P != 4);
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

void menu() {
	system("cls");
	cout << "			MENU 		\n";
	cout << "	1. Pila				\n";
	cout << "	2. Salir			\n";
	cout << "	Ingrese una op1cion: ";
}

void main2() {
	system("cls");
	do {
		menu();
		cin >> op1;
		switch (op1) {
		case 1: {
			system("cls");
			cout << "\t\tPILA\n\n";
			menup();
			cin >> op1P;
			_getch();
		}
		default:
			cout << "OPCION NO VALIDA...";
			_getch();
			break;
		}
	} while (op1 != 2);
	_getch();
}