/*#pragma once
///Listas Simplemente Enlazadas
///#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct dato {
	int i;
	dato *s;
}*a, *i, *p, *e;

int da;

int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar(void);

int main3() {
	menu();
}

void menu(void) {
	int opc, da;
	do {
		cout << "\n\n\t\t           MENU\n";
		cout << "\t\t1 - Buscar Datos\n";
		cout << "\t\t2 - Insertar Datos\n";
		cout << "\t\t3 - Mostrar Todos Los Datos\n";
		cout << "\t\t4 - Borrar Un Dato\n";
		cout << "\t\t5 - Guardar Datos A Archivo\n";
		cout << "\t\t6 - Cargar Datos De Archivo\n";
		cout << "\t\t0 - Salida\n";
		cout << "\t\tSeleccione Opcion: ";
		cin >> opc;
		switch (opc) {
		case 0: cout << "\n\nSaliendo del programa...";
			_getch();
			p = i;
			while (p) {
				a = p;
				p = p->s;
				delete(a);
			}
			exit(0);
		case 1: cout << "\n\nIngrese dato a buscar: ";
			cin >> da;
			if (buscar(da))
				cout << "\n\nDato existe...";
			else
				cout << "\n\nDato NO EXISTE...";
			_getch();
			break;
		case 2: cout << "Ingrese dato: ";
			cin >> da;
			insertar(da);
			break;
		case 3: mostrar();
			break;
		case 4: borrar();
			break;
		case 5: guardar();
			break;
		case 6: cargar();
			break;
		default: cout << "\n\nOPCION NO VALIDA!!!";
			_getch();
		}
	} while (opc);
}

void mostrar(void) {
	int cont = 1;
	if (!i) {
		cout << "\n\nNO HAY LISTA PARA MOSTRAR!!!";
		_getch();
		return;
	}
	p = i;
	cout << endl << endl;
	while (p) {
		cout << cont++ << " - Valor = " << p->i << endl;
		p = p->s;
	}
	cout << "\n\nEso es todo";
	_getch();
}

int buscar(int d) {
	if (!i) {
		cout << "No hay datos en la lista!!!";
		_getch();
		return(0);
	}
	p = i;
	a = NULL;
	while (p->s && p->i<d) {
		a = p;
		p = p->s;
	}
	return(p->i == d ? 1 : 0);
}

void insertar(int dat) {
		i = new dato;
	if (!i) {
		i->s = NULL;
		i->i = dat;
		return;
	}
	if (buscar(dat)) {
		cout << "\n\nDato existente...";
		_getch();
		return;
	}
	e = new dato;
	e->i = dat;
	if (p == i && p->s) {
		e->s = p;
		i = e;
		return;
	}
	if (p == i && !p->s) {
		if (p->i < e->i) {
			p->s = e;
			e->s = NULL;
		}
		else {
			e->s = p;
			i = e;
		}
		return;
	}
	if (p->s) {
		a->s = e;
		e->s = p;
		return;
	}
	if (e->i > p->i) {
		e->s = NULL;
		p->s = e;
	}
	else {
		a->s = e;
		e->s = p;
	}
}

void borrar(void) {
	cout << "\n\nIngrese dato a eliminar: ";
	cin >> da;
	if (buscar(da)) {
		if (a)
			a->s = p->s;
		else
			i = p->s;
		delete(p);
		cout << "\n\nDato eliminado...";
	}
	else
		cout << "\n\nDato no se encuentra!!!";
	_getch();
}

void guardar(void) {
	FILE arch;
	///arch = fopen_s("DATOS-A.TXT", "w");
	fopen_s(arch, "DATOS-A.TXT", "w");
	if (!i) {
		cout << "\n\nNO HAY LISTA PARA GUARDAR!!!";
		_getch();
		return;
	}
	p = i;
	while (p) {
		fprintf(arch, "%i\n", p->i);
		p = p->s;
	}
	cout << "\n\nArchivo Guardado...";
	fclose(arch);
	_getch();
}

void cargar(void) {
	int c, x;
	FILE *arch;
	//arch = fopen_s("DATOS-A.TXT", "r");
	fopen_s(arch, "DATOS-A.TXT", "r");
	if (!arch) {
		cout << "\n\nNO EXISTE EL ARCHIVO!!!";
		_getch();
		return;
	}
	do {
		c = fscanf_s(arch, "%i\n", &x);
		if (c != EOF) {
			insertar(x);
		}
	} while (c != EOF);
	cout << "\n\nArchivo Cargado...";
	fclose(arch);
	_getch();
}
*/