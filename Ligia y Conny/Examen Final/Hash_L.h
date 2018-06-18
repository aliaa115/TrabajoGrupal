#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

///variables glovales
int dato_d;
int MAX_d = 5;

///prototipos
struct llave_d;
struct clave_d;
clave_d *nuevaC_d(); llave_d *nuevaL_d();
llave_d *recoL_d(); clave_d *recoC_d(clave_d *);
int funcHash_d(); void inicL_d();
void iniciarLlave_d(); llave_d *buscarLlave_d(int);
void insertarClave_d(llave_d*); void irEnLlave_d();
void pedirDato_d(); void imprimir_d(); void elim_d(); void buscar_d();

///funciones

struct llave_d {
	struct llave_d *s;
	struct llave_d *a;
	int illa;
	struct clave_d *clave;
}*inicioL_d, *finL_d, *recorrerL_d, *nuevoL_d;

struct clave_d {
	struct clave_d *a;
	struct clave_d *s;
	int icla;
}*inicioC_d, *finC_d, *recorrerC_d, *nuevoC_d;

clave_d *nuevaC_d() {
	nuevoC_d = new clave_d;
	if (nuevoC_d) {
		nuevoC_d->s = NULL;
		nuevoC_d->icla = dato_d;
		nuevoC_d->a = NULL;
	}
	return nuevoC_d;
}

llave_d *nuevaL_d() {
	nuevoL_d = new llave_d;
	if (nuevoL_d) {
		nuevoL_d->a = NULL;
		nuevoL_d->s = NULL;
		nuevoL_d->illa = 0;
		nuevoL_d->clave = NULL;
	}
	return nuevoL_d;
}

int funcHash_d() {
	return (dato_d % MAX_d);
}

void inicL_d() {
	inicioL_d = nuevaL_d();
	inicioL_d->illa = 0;
	cout << "\n\tSE INGRESO LA CLAVE 0 ";
}

llave_d *recoL_d() {
	recorrerL_d = inicioL_d;
	while (recorrerL_d->s) {
		recorrerL_d = recorrerL_d->s;
	}
	return recorrerL_d;
}

clave_d *recoC_d(clave_d *i) {
	recorrerC_d = i;
	while (recorrerC_d->s) {
		recorrerC_d = recorrerC_d->s;
	}
	return recorrerC_d;
}

void iniciarLlave_d() {
	llave_d *n, *aux;
	for (int i = 0; i < MAX_d; i++) {
		if (!inicioL_d) inicL_d();
		else {
			n = nuevaL_d();
			aux = recoL_d();
			n->illa = i;
			cout << "\n\tSE INGRESO LA CLAVE " << i;
			aux->s = n;
			n->a = aux;
		}
	}
}

llave_d *buscarLlave_d(int fH) {
	recorrerL_d = inicioL_d;
	while (recorrerL_d->s) {
		if (recorrerL_d->illa == fH)
			return recorrerL_d;
		recorrerL_d = recorrerL_d->s;
	}
	return recorrerL_d;
}

void insertarClave_d(llave_d *a) {
	clave_d *n, *i;
	if (!a->clave) { a->clave = nuevaC_d(); }
	else {
		i = recoC_d(a->clave);
		n = nuevaC_d();
		i->s = n;
	}
}

void irEnLlave_d() {
	llave_d *insertarL;
	insertarL = buscarLlave_d(funcHash_d());
	insertarClave_d(insertarL);
}

void pedirDato_d() {
	char a[100];
	cout << "\n\n\n\n\t\t|INGRESO DE DATO|";
	cout << "\n\n\tingrese el dato para la tabla de hash:  ";
	cin >> dato_d;
	cout << "\t                                   residuo: " << dato_d % MAX_d;
	irEnLlave_d();
}

void imprimir_d() {
	recorrerL_d = inicioL_d;

	cout << "\n\n\n\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	for (int i = 0; i < MAX_d; i++) {
		cout << "\n\t" << recorrerL_d->illa << " \t|";
		if (recorrerL_d->clave) {
			recorrerC_d = recorrerL_d->clave;
			while (recorrerC_d) {
				cout << "\t( " << recorrerC_d->icla << " ) |";
				recorrerC_d = recorrerC_d->s;
			}
		}
		cout << "\n";
		for (int i = 0; i < 100; i++)
			cout << "-";
		recorrerL_d = recorrerL_d->s;
	}
}

void buscar_d() {
	cout << "\n\n\t\t|BUSCAR|\n";
	cout << "\n\tingrese el valor a buscar: ";
	cin >> dato_d;
	recorrerL_d = inicioL_d;
	while (recorrerL_d) {
		if (recorrerL_d->illa == (dato_d % MAX_d))break;
		recorrerL_d = recorrerL_d->s;
	}
	if (!recorrerL_d->clave)cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	else {
		recorrerC_d = recorrerL_d->clave;
		while (recorrerC_d) {
			if (recorrerC_d->icla == dato_d) { cout << "\n\tEL DATO SI ESTA EN LA LISTA..."; break; break; }
			recorrerC_d = recorrerC_d->s;
		}
	}
}

void elim_d() {
	clave_d *aux;
	cout << "\n\n\t\t|ELIMINAR|\n";
	cout << "\n\tingrese el valor a eliminar: ";
	cin >> dato_d;
	recorrerL_d = inicioL_d;
	while (recorrerL_d) {
		if (recorrerL_d->illa == (dato_d % MAX_d))break;
		recorrerL_d = recorrerL_d->s;
	}
	if (!recorrerL_d->clave)cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	else {
		recorrerC_d = recorrerL_d->clave;
		aux = recorrerC_d;
		while (recorrerC_d) {
			if (recorrerC_d->icla == dato_d) {
				if (recorrerC_d == recorrerL_d->clave) recorrerL_d->clave = recorrerC_d->s;
				else { aux->s = recorrerC_d->s; }
				free(recorrerC_d);
				cout << "\n\tEL DATO BORRADO DE LA LISTA...";
				break; break;
			}
			aux = recorrerC_d;
			recorrerC_d = recorrerC_d->s;
		}
		cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	}
}

void menu6() {
	int op = 1;
	while (op != 0) {
		system("cls");
		cout << "\n\n\t\t\tMENU:";
		cout << "\n\t\t1| INSERTAR";
		cout << "\n\t\t2| IMPRIMIR";
		cout << "\n\t\t3| BUSCAR";
		cout << "\n\t\t4| ELIMINAR";
		cout << "\n\t\t0| SALIR";
		cout << "\n\t\t--------------> ";
		cin >> op;
		switch (op) {
		case 1:
			pedirDato_d();
			break;
		case 2:
			imprimir_d();
			_getch();
			break;
		case 3:
			buscar_d();
			_getch();
			break;
		case 4:
			elim_d();
			_getch();
			break;
		default:
			break;
		}
	}
}

int main6() {

	cout << "\n\n\t\tincio del programa::";
	cout << "\n\tingrese el tamaño del vector: ";
	cin >> MAX_d;
	if (2 % MAX_d == 0)MAX_d = MAX_d + 1;

	iniciarLlave_d();
	system("cls");
	menu6();
	_getch();
	return 0;
}
