#pragma once
///Lista Doblemente enlazada
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define Ascendente 1
#define Descendente 0

using namespace std;

typedef struct Nodo {
	int dato;
	struct Nodo *sgt;
	struct Nodo *ant;
}TNodo;

typedef struct LE {
	TNodo *inicio;
}TLE;

TNodo *crearNodo(int x) {
	TNodo *nodo = (TNodo*)malloc(sizeof(TNodo));
	nodo->dato = x;
	nodo->sgt = NULL;
	nodo->ant = NULL;
	return nodo;
}

TLE *crearLista() {
	TLE *lista = (TLE*)malloc(sizeof(TLE));
	lista->inicio = NULL;
	return lista;
}

void Insertar(TLE *lista, int x) {
	TNodo *nodo = crearNodo(x);
	TNodo *p = NULL;
	if (lista->inicio == NULL) {
		lista->inicio = nodo;
		nodo->ant == NULL;
	}
	else {
		p = lista->inicio;
		while (p->sgt != NULL)
			p = p->sgt;
		p->sgt = nodo;
		nodo->ant = p;
	}
}

void Eliminar(TLE *lista, int dato) {
	TNodo *p = lista->inicio;
	TNodo *ant = NULL;
	int encontrado = 0;
	while ((p != NULL) && (!encontrado)) {
		if (p->dato == dato)
			encontrado = 1;
		else {
			ant = p;
			p = p->sgt;
		}
	}
	if (p != NULL) {
		if (ant == NULL)
			lista->inicio = (lista->inicio)->sgt;
		else {
			ant->sgt = p->sgt;
			p->sgt->ant = ant;
		}
		free(p);
	}
}

void Borrar(TLE *lista) {
	TNodo *p = NULL;
	while (lista->inicio != NULL) {
		p = lista->inicio;
		lista->inicio = p->sgt;
		p->sgt->ant == NULL;
		free(p);
	}
}

void Reportar(TLE *lista, int Orden) {
	TNodo *p = lista->inicio;
	if (Orden == Ascendente) {
		cout << "      lista -> ";
		while (p != NULL) {
			cout << p->dato << " <-> ";
			p = p->sgt;
		}
		cout << "NULL";
	}
	else {
		cout << "      NULL ";
		while (p->sgt != NULL)
			p = p->sgt;
		while (p != NULL) {
			cout << " <-> " << p->dato;
			p = p->ant;
		}
		cout << " <- Lista";
	}
	cout << endl << endl;
	system("pause");
	cout << endl;
}

void Vacia(TLE *lista) {
	if (lista->inicio == NULL)
		cout << endl << "      - La Lista Esta Vacia !!! " << endl;
	else
		cout << endl << "      - La Lista No Esta Vacia !!! ";
	cout << endl << endl;
	system("pause");
	cout << endl;
}

int main4() {
	system("color f3");
	TLE *L = crearLista();
	int N, E, i = 0;
	int opcion;
	cout << "          MENU LISTAS DOBLES" << endl;
	cout << "          ------------------ ";
	while (1) {
		cout << endl << endl;
		cout << "   -------------------------------- " << endl;
		cout << "   | 1.  Insertar                  |" << endl;
		cout << "   | 2.  Eliminar Elemento         |" << endl;
		cout << "   | 3.  Borrar Lista              |" << endl;
		cout << "   | 4.  Mostrar Lista Ascendente  |" << endl;
		cout << "   | 5.  Mostrar Lista Descendente |" << endl;
		cout << "   | 6.  Lista Esta Vacia          |" << endl;
		cout << "   | 7.  Salir                     |" << endl;
		cout << "   --------------------------------" << endl;
		do {
			cout << endl << endl << "   -> Ingrese Opcion" << endl;
			cout << "      --------------->  ";
			cin >> opcion;
		}
		while (opcion < 1 || opcion > 7);
		switch (opcion) {
		case 1:
			i++;
			cout << endl << "       - Ingrese [" << i << "] elemento: ";
			cin >> N;
			Insertar(L, N);
			break;
		case 2:
			cout << endl << "       - Ingrese Elemento a Eliminar: ";
			cin >> E;
			Eliminar(L, E);
			break;
		case 3:
			Borrar(L);
			cout << endl << endl;
			cout << "       - Se Elimino La Lista Correctamente... ";
			cout << endl << endl;
			system("pause");
			cout << endl;
			break;
		case 4:
			cout << endl;
			Reportar(L, Ascendente);
			cout << endl;
			break;
		case 5:
			cout << endl;
			Reportar(L, Descendente);
			cout << endl;
			break;
		case 6:
			Vacia(L);
			break;
		case 7:
			exit(1);
		default:
			cout << endl << endl;
			cout << "     La Opcion No es Valida !!!!!!!!!:";
		}
	}
	cout << endl << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
