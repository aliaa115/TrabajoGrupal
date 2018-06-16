#pragma once
#define CRT_NO_WARNING_SECURITY
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct cola {
	char nombre[20];
	struct cola *sC;
}*c, *a, *f;

int op1 = 0, opC = 0;

void insertarC(void);
void visualizarC(void);
int atenderC();
int menuc();
void menu();

int menuc() {
	system("cls");
	cout << "\t\t	MENU COLA\n";
	cout << "\t\t PROGRAMA PARA GESTIONAR TURNOS PARA ATENCION\n\n";
	cout << "\t1. ASIGNAR TURNO\n";
	cout << "\t2. VISUALIZAR TURNOS EN ESPERA\n";
	cout << "\t3. ATENDER TURNO\n";
	cout << "\t4. SALIR";
	cout << "\tIngrese una opcion: ";
	opC = _getch();
	switch (opC) {
	case '1':
		insertarC();
		break;
	case '2':
		visualizarC();
		break;
	case '3':
		atenderC();
		break;
	case '4':
		delete a;
		system("cls");
		cout << "\t\tHASTA PRONTO...\n";
		Sleep(2000);
		exit(1);
		break;
	default:
		break;
	}while (opC != '4');
	return 0;
}

void insertarC(void) {
	a = new cola;
	system("cls");
	cout << "\t\tASIGNACION DE TURNOS\n\n";
	cout << "\n\tIngrese el nombre: ";
	gets_s(a->nombre,20);
	a->sC = NULL;
	if (f == NULL) {
		f = c = a;
	}
	else {
		f->sC = a;
		f = a;
	}
}

void visualizarC(void) {
	system("cls");
	if (c == NULL) {
		cout << "\t\tNO HAY PERSONAS EN LA COLA...\n";
		_getch();
	}
	else {
		cout << "\n\tLISTADO DE USUARIOS EN ESPERA...\n";
		a = c;
		while (a != NULL) {
			cout << a->nombre << "\n";
			a = a->sC;
		}
	}
	_getch();
}

int atenderC() {
	system("cls");
	cout << "\t\t\nSALIDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n";
	_getch();
}

void menu() {
	system("cls");
	cout << "			MENU 		\n";
	cout << "	1. Cola 			\n";
	cout << "	2. Salir			\n";
	cout << "	Ingrese una opcion: ";
}

int main() {
	system("cls");
	do {
		menu();
		cin >> op;
		switch (op) {
		case 1: {
			system("cls");
			cout << "\t\tPILA\n\n";
			menuc();
			cin >> opC;
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
