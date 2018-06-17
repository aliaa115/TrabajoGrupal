#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

///variables glovales
int dato;
string sdato;
int MAX = 5;

///prototipos
struct curso;
struct unidad;
unidad *nuevaC(); curso *nuevaL();
curso *recoL(); unidad *recoC(unidad *);
int funcHash(); void inicL();
void iniciarcurso(); curso *buscarcurso(int);
void insertarunidad(curso*); void irEncurso(string);
void pedirDato(); void imprimir(); void buscar();

///funciones

struct curso {
	struct curso *s;
	int illa;
	string cu;
	struct unidad *unidad;
}*inicioCur, *finCur, *recorrerCur, *nuevoCur;

struct unidad {
	struct unidad *s;
	string uni;
}*inicioC, *finC, *recorrerC, *nuevoC;

unidad *nuevaC() {
	nuevoC = new unidad;
	if (nuevoC) {
		nuevoC->s = NULL;
		nuevoC->uni = sdato;
	}
	return nuevoC;
}

curso *nuevaL() {
	nuevoCur = new curso;
	if (nuevoCur) {
		nuevoCur->s = NULL;
		nuevoCur->illa = 0;
		nuevoCur->unidad = NULL;
	}
	return nuevoCur;
}

void inicL() {
	inicioCur = nuevaL();
	inicioCur->illa = 0;
	cout << "\n\tINGRESE LA CURSO PARA LA POSICION 0: ";
	cin >> inicioCur->cu;
}

curso *recoL() {
	recorrerCur = inicioCur;
	while (recorrerCur->s) {
		recorrerCur = recorrerCur->s;
	}
	return recorrerCur;
}

unidad *recoC(unidad *i) {
	recorrerC = i;
	while (recorrerC->s) {
		recorrerC = recorrerC->s;
	}
	return recorrerC;
}

void iniciarcurso() {
	curso *n, *aux;
	for (int i = 0; i < MAX; i++) {
		if (!inicioCur) inicL();
		else {
			n = nuevaL();
			aux = recoL();
			n->illa = i;
			cout << "\n\tINGRESE LA CURSO PARA LA POSICION " << i << ": ";
			cin >> n->cu;
			aux->s = n;
		}
	}
}

curso *buscarcurso(string curso) {
	recorrerCur = inicioCur;
	while (recorrerCur->s) {
		if (recorrerCur->cu == curso)
			return recorrerCur;
		recorrerCur = recorrerCur->s;
	}
	return recorrerCur;
}

void insertarunidad(curso *a) {
	unidad *n, *i;
	if (!a->unidad) { a->unidad = nuevaC(); }
	else {
		i = recoC(a->unidad);
		n = nuevaC();
		i->s = n;
	}
}

void irEncurso(string cur) {
	curso *insertarL;
	insertarL = buscarcurso(cur);
	insertarunidad(insertarL);
}

void pedirDato() {
	char a[100];
	string cur;
	cout << "\n\n\n\n\t\t|INGRESO DE DATO|";
	cout << "\n\n\tingrese el curso:";
	cin >> cur;
	cout << "\n\n\tingrese el dato para la tabla de hash:  ";
	cin >> sdato;
	cout << "\t                                   residuo: " << dato % MAX;
	irEncurso(cur);
}

void imprimir() {
	recorrerCur = inicioCur;

	cout << "\n\n\n\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	for (int i = 0; i < MAX; i++) {
		cout << "\n\t" << recorrerCur->illa << " " << recorrerCur->cu << "\t|";
		if (recorrerCur->unidad) {
			recorrerC = recorrerCur->unidad;
			while (recorrerC) {
				cout << "\t" << recorrerC->uni << " |";
				recorrerC = recorrerC->s;
			}
		}
		cout << "\n";
		for (int i = 0; i < 100; i++)
			cout << "-";
		recorrerCur = recorrerCur->s;
	}
}

void buscar() {
	string cur;
	cout << "\n\n\t\t|BUSCAR|\n";
	cout << "\n\tingrese el curso: ";
	cin >> cur;
	recorrerCur = inicioCur;
	while (recorrerCur) {
		if (recorrerCur->cu == cur)break;
		recorrerCur = recorrerCur->s;
	}
	if (!recorrerCur->unidad)cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	else {
		cout << "\n\t" << recorrerCur->illa << " " << recorrerCur->cu << "\t|";
		if (recorrerCur->unidad) {
			recorrerC = recorrerCur->unidad;
			while (recorrerC) {
				cout << "\t" << recorrerC->uni << " |";
				recorrerC = recorrerC->s;
			}
		}
	}
}

void menuHashL() {
	int op = 1;
	while (op != 0) {
		system("cls");
		cout << "\n\n\t\t\tMENU:";
		cout << "\n\t\t1| INSERTAR";
		cout << "\n\t\t2| IMPRIMIR";
		cout << "\n\t\t3| BUSCAR";
		cout << "\n\t\t0| SALIR";
		cout << "\n\t\t--------------> ";
		cin >> op;
		switch (op) {
		case 1:
			pedirDato();
			break;
		case 2:
			imprimir();
			_getch();
			break;
		case 3:
			buscar();
			_getch();
			break;
		default:
			break;
		}
	}
}

int main7() {

	cout << "\n\n\t\tincio del programa::";
	cout << "\n\tingrese el tamaño del vector: ";
	cin >> MAX;
	if (2 % MAX == 0)MAX = MAX + 1;

	iniciarcurso();
	system("cls");
	menuHashL();
	_getch();
	return 0;
}