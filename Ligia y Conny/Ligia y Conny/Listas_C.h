#pragma once
///Listas Circulares
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct empleado {
	int ident;
	char ap[20], nom[20], cargo[20];
	int sueldo;
	struct empleado *avanc;
};

empleado* insertar_nodo_inicial(void);
void insertar_nodos_circular(empleado *&, int c);
int progenc(empleado *);
void empleadosmayora(empleado *);
void sumanomina(empleado *);
char opciones(empleado *);
void ordenar(empleado*);
void imprime_lista_circ(empleado*);
void eliminar_nodo_circ(empleado *&cab, int i);

char opciones(empleado * cab) {
	char a;
	cout << "\n\n\t\tMENU\n";
	cout << "\n\t\t1. Crear Nodo Inicial";
	cout << "\n\t\t2. Insertar Nuevo Dato";
	cout << "\n\t\t3. Programadores En C++";
	cout << "\n\t\t4. Sueldo Mayor A $2'500.000";
	cout << "\n\t\t5. Motrar Suma De Sueldos Empleados";
	cout << "\n\t\t6. Imprimir Lista";
	cout << "\n\t\t7. Borrar Nodo";
	cout << "\n\t\t8. Salida";
	cout << "\n\t\tINGRESE OPCION: ";
	cin >> a;
	return a;
}

void main() {
	int i, c;
	char opcion = 0;
	empleado *cab = NULL;
	while (opcion != '8') {
		opcion = opciones(cab);
		switch (opcion) {
		case '1':
			cab = insertar_nodo_inicial();
			break;
		case '2':
			cout << "\tIngrese su identificacion: ";
			cin >> c;
			insertar_nodos_circular(*&cab, c);
			break;
		case '3':
			cout << "\tEn la empresa hay " << progenc(cab) << " programador(es) de  c++";
			break;
		case '4':
			empleadosmayora(cab);
			break;
		case '5':
			sumanomina(cab);
			break;
		case '6':
			imprime_lista_circ(cab);
			break;
		case '7':
			cout << "\tIngrese su identificacion: ";
			cin >> i;
			eliminar_nodo_circ(*&cab, i);
			break;
		case '8':
			cout << "\n\n\n\tSalida...";
			system("pause>null");
			break;
		default:
			cout << "\tNo se encontro dicha opcion!!!";
		}
	}
}

empleado* insertar_nodo_inicial() {
	empleado *crear;
	crear = new empleado;
	cout << "\tIdentificacion: ";
	cin >> crear->ident;
	cout << "\tApellido: ";
	cin >> crear->ap;
	cout << "\tNombre: ";
	cin >> crear->nom;
	cout << "\tCargo: ";
	cin >> crear->cargo;
	cout << "\tSueldo: ";
	cin >> crear->sueldo;
	crear->avanc = crear;
	return crear;
}

void insertar_nodos_circular(empleado *&cab, int c) {
	empleado *aux;
	empleado *r;
	if (cab != NULL) {
		r = cab;
		aux = new empleado;
		while (r->ident != c && r->avanc != cab)
			r = r->avanc;
		if (r == cab) {
			cout << "\tIdentificacion: ";
			cin >> aux->ident;
			cout << "\tApellido: ";
			cin >> aux->ap;
			cout << "\tNombre: ";
			cin >> aux->nom;
			cout << "\tCargo: ";
			cin >> aux->cargo;
			cout << "\tSueldo: ";
			cin >> aux->sueldo;
			aux->avanc = r->avanc;
			r->avanc = aux;
			r = aux;
		}
		else {
			aux->avanc = r->avanc;
			r->avanc = aux;
			cout << "\tIdentificacion: ";
			cin >> aux->ident;
			cout << "\tApellido: ";
			cin >> aux->ap;
			cout << "\tNombre: ";
			cin >> aux->nom;
			cout << "\tCargo: ";
			cin >> aux->cargo;
			cout << "\tSueldo: ";
			cin >> aux->sueldo;
		}
	}
	else
		cout << "\tNo hay nodo inicial de lista por favor digite 1";
}

int progenc(empleado*cab) {
	empleado *q;
	int cant = 0;
	q = cab;
	if (cab) {
		if (strcmp(q->cargo, "\tProgramadores_en_c++") == 0)
			cout << "\n";
		cant = cant + 1;
		while (q->avanc != cab) {
			if (strcmp(q->cargo, "\tProgramadores_en_c++") == 0)
				cout << "\n";
			cant = cant + 1;
			q = q->avanc;
		}
	}
	else
		cout << "\tNo existe lista!!!";
	return cant;
	_getch();
}

void empleadosmayora(empleado *cab) {
	empleado *p;
	p = cab;
	if (cab) {
		if (cab->sueldo>2500000) {
			cout << "\tIdentificacion: " << cab->ident;
			cout << "n";
			cout << "\tApellido: " << cab->ap;
			cout << "n";
			cout << "\tNombre: " << cab->nom;
			cout << "n";
			cout << "\tCargo: " << cab->cargo;
			cout << "n";
			cout << "\tSueldo: " << cab->sueldo;
			cout << "n";
		}
		p = cab->avanc;
		while (p != cab) {
			if (p->sueldo>2500000 && p != cab) {
				cout << "\n";
				cout << "\tIdentificacion: " << p->ident;
				cout << "\n";
				cout << "\tApellido: " << p->ap;
				cout << "\n";
				cout << "\tNombre: " << p->nom;
				cout << "\n";
				cout << "\tCargo: " << p->cargo;
				cout << "\n";
				cout << "\tSueldo: " << p->sueldo;
				cout << "\n";
			}
			p = p->avanc;
		}
	}
	else
		cout << "\tNo existe lista!!!";
	_getch();
}

void sumanomina(empleado *cab) {
	empleado *q;
	int sumnomina = 0;
	q = cab->avanc;
	if (cab) {
		sumnomina = cab->sueldo + sumnomina;
	}
	while (q != cab) {
		sumnomina = cab->sueldo + sumnomina;
		q = q->avanc;
	}
	cout << "\tEl total de la nomina es: " << sumnomina;
	_getch();
}

void imprime_lista_circ(empleado*cab) {
	empleado *q;
	if (cab == NULL)
		cout << "\tNo hay lista!!!";
	else
		if (cab->avanc == cab) {
			cout << "\n";
			cout << "\n";
			cout << "\tIdentificacion:" << cab->ident;
			cout << "\n";
			cout << "\tapellido:" << cab->ap;
			cout << "\n";
			cout << "\tnombre:" << cab->nom;
			cout << "\n";
			cout << "\tcargo:" << cab->cargo;
			cout << "\n";
			cout << "\tsueldo:" << cab->sueldo;
			cout << "\n";
			cout << "\n";
		}
		else {
			q = cab;
			cout << "\n";
			cout << "\n";
			cout << "\tIdentificacion:" << cab->ident;
			cout << "\n";
			cout << "\tapellido:" << cab->ap;
			cout << "\n";
			cout << "\tnombre:" << cab->nom;
			cout << "\n";
			cout << "\tcargo:" << cab->cargo;
			cout << "\n";
			cout << "\tsueldo:" << cab->sueldo;
			cout << "\n";
			cout << "\n";
			q = cab->avanc;
			do {
				cout << "\tOdentificacion:" << q->ident;
				cout << "\n";
				cout << "\tapellido:" << q->ap;
				cout << "\n";
				cout << "\tnombre:" << q->nom;
				cout << "\n";
				cout << "\tcargo:" << q->cargo;
				cout << "\n";
				cout << "\tsueldo:" << q->sueldo;
				cout << "\n";
				cout << "\n";
				q = q->avanc;
			} while (q != cab);
		}
	_getch();
}

void eliminar_nodo_circ(empleado *&cab, int i) {
	empleado *q, *r;
	q = r = cab;
	if (cab == NULL)
		cout << "\tNo hay cabeza!!!";
	else
		if (cab->avanc == cab && cab->ident == i) {
			delete(q);
		}
		else
			while ((q->ident != i) && (q->avanc != cab)) {
				q = q->avanc;
			}
	if (cab->avanc == q) {
		cab->avanc = q->avanc;
		delete(q);
	}
	else {
		while (r->avanc != q) {
			r = r->avanc;
		}
		r->avanc = q->avanc;
		delete(q);
	}
}
