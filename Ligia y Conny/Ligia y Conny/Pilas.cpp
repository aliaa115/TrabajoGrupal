#define CRT_NO_WARNING_SECURITY
#include <iostream>
#include <conio.h>

using namespace std;

struct pila {
	int num;
	struct pila *sP;
}*inicio = NULL, *final = NULL;

int op = 0;

void menu();
void insertar();
void extraer();
void visualizar();

void menu() {
	system("cls");
	cout << "Menu Pila\n";
	cout << "1. Insertar\n";
	cout << "2. Visualizar\n";
	cout << "3. Extraer";
	cout << "4. Salir";
	cout << "Ingrese una opcion: ";
	cin >> op;
	switch (op) {
	case 1:
		insertar();
		break;
	case 2:
		visualizar();
		break;
	case 3:
		extraer();
		break;
	case 4:
		exit(0);
		break;
	default:
		break;
	}while (op != 4);
}

void insertar(){
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

void extraer() {
	if (final == NULL) {
		system("cls");
		cout << "NO HAY ELEMENTOS A ELIMINAR...\n";
	}
	else {
		inicio = final;
		system("cls");
		cout << "Funcion Eliminar elementos de la pila\n\n";
		cout << "El dato a eliminar es: " << inicio->num;
		_getch();
		final = final->sP;
		delete inicio;
	}
}

void visualizacion() {
	if (final == NULL) {
		system("cls");
		cout << "No hay elementos a listar\n";
	}
	else {
		system("cls");
		cout << "Elementos insertados en la pila\n\n";
		inicio = final;
		while (inicio != NULL) {
			cout << "Numero: " << inicio->num << "\n";
			inicio = inicio->sP;
		}
	}
	_getch();
}

