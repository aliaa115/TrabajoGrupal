#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

using namespace std;

struct arbol {
	int dato;
	struct arbol *izq;
	struct arbol *der;
}*raiz;

enum { FALSO = 0, VERDADERO };

/*PROTOTIPOS*/
void inicializar(void);
int vacio(struct arbol *hoja);
int eshoja(struct arbol *hoja);
struct arbol *insertar(struct arbol *raiz, struct arbol *hoja, int num);
int busqueda(struct arbol *hoja, int num);
int alturax(struct arbol *hoja, int num);
int alturafull(struct arbol *hoja, int *altura);
void auxaltura(struct arbol *hoja, int *altura, int cont);
int nodos(struct arbol *hoja);
void auxnodos(struct arbol *hoja, int *cont);
int sumnodos(struct arbol *hoja);
void auxsumnodos(struct arbol *hoja, int*);
struct arbol *borrarx(struct arbol *hoja, int num);
struct arbol *borrari(struct arbol *hoja, int num);
struct arbol *podar(struct arbol *hoja);
void preorden(struct arbol *hoja);
void inorden(struct arbol *hoja);
void posorden(struct arbol *hoja);
void menu_recorridos(void);
void menu_busquedas(void);
void menu_alturas(void);
void menu_nodos(void);
void menu_podar(void);

void inicializar(void) {
	raiz = NULL;
}

int vacio(struct arbol *hoja) {
	if (!hoja) return VERDADERO;
	return FALSO;
}

int eshoja(struct arbol *hoja) {
	if (hoja->izq == NULL && hoja->der == NULL)
		return VERDADERO;
	return FALSO;
}

struct arbol *insertar(struct arbol *raiz, struct arbol *hoja, int num) {
	if (!hoja) {
		hoja = (struct arbol *) malloc(sizeof(struct arbol));
		hoja->dato = num;
		hoja->izq = NULL;
		hoja->der = NULL;
		if (!raiz) return hoja;
		else if (num<raiz->dato) raiz->izq = hoja;
		else raiz->der = hoja;
		return hoja;
	}
	else if (num<hoja->dato)
		insertar(hoja, hoja->izq, num);
	else insertar(hoja, hoja->der, num);
	return raiz;
}

int busqueda(struct arbol *hoja, int num) {
	while (hoja) {
		if (num == hoja->dato) return VERDADERO;
		else {
			if (num<hoja->dato) hoja = hoja->izq;
			else hoja = hoja->der;
		}
	}
	return FALSO;
}

int alturax(struct arbol *hoja, int num) {
	int altura = 1;

	while (hoja) {
		if (num == hoja->dato) return altura;
		else {
			altura++;
			if (num<hoja->dato) hoja = hoja->izq;
			else hoja = hoja->der;
		}
	}
	return FALSO;
}

int alturaDere(struct arbol *hoja, int val) {
	if (!hoja->der) return 0;
	int altT = 0;
	alturafull(raiz, &altT);
	int altDer;
	altDer = alturax(hoja->der, val);
	return altT - altDer;
}

int alturaIzqui(struct arbol *hoja, int val) {
	if (!hoja) return 0;
	int altT = 0;
	alturafull(raiz, &altT);
	int altIzq;
	altIzq = alturax(hoja->izq, val);
	return altT - altIzq;
}

void Fe(struct arbol *hoja, int dato) {
	int altIz, altDer, Fe;
	altDer = alturaDere(hoja, dato);
	altIz = alturaIzqui(hoja, dato);
	Fe = altDer - altIz;
	cout << "\n\n\tAltura por la derecha: " << altDer;
	cout << "\n\tAltura por la izquierda: " << altIz;
	cout << "\n\tFe:                      " << Fe;
}

void informacionNodo(int alturaDere, int  alturaIzqui, int Fe) {

}

int alturafull(struct arbol *hoja, int *altura) {
	auxaltura(hoja, altura, 1);
	return *altura;
}

void auxaltura(struct arbol *hoja, int *altura, int cont) {
	if (!hoja) return;

	auxaltura(hoja->izq, altura, cont + 1);
	auxaltura(hoja->der, altura, cont + 1);
	if (eshoja(hoja) != 0 && cont>*altura) *altura = cont;
}

int nodos(struct arbol *hoja) {
	int nodos = 0;
	auxnodos(hoja, &nodos);
	return nodos;
}

void auxnodos(struct arbol *hoja, int *cont) {
	if (!hoja) return;

	(*cont)++;
	auxnodos(hoja->izq, cont);
	auxnodos(hoja->der, cont);
}

int sumnodos(struct arbol *hoja) {
	int suma = 0;
	auxsumnodos(hoja, &suma);
	return suma;
}


void auxsumnodos(struct arbol *hoja, int *sum) {
	if (!hoja) return;

	(*sum) = (*sum) + hoja->dato;
	auxsumnodos(hoja->izq, sum);
	auxsumnodos(hoja->der, sum);
}

struct arbol *borrarx(struct arbol *hoja, int num) {
	if (hoja->dato == num) {
		struct arbol *p, *p2;

		if (vacio(hoja)) {
			free(hoja);
			hoja = NULL;
			return hoja;
		}
		else if (hoja->izq == NULL) {
			p = hoja->der;
			free(hoja);
			return p;
		}
		else if (hoja->der == NULL) {
			p = hoja->izq;
			free(hoja);
			return p;
		}
		else {
			p = hoja->der;
			p2 = hoja->der;
			while (p->izq) p = p->izq;
			p->izq = hoja->izq;
			free(hoja);
			return p2;
		}
	}
	else if (num<hoja->dato)
		hoja->izq = borrarx(hoja->izq, num);
	else
		hoja->der = borrarx(hoja->der, num);
	return hoja;
}

struct arbol *borrari(struct arbol *hoja, int num) {
	if (hoja->dato == num) {
		struct arbol *p, *p2;

		if (vacio(hoja)) {
			free(hoja);
			hoja = NULL;
			return hoja;
		}
		else if (hoja->izq == NULL) {
			p = hoja->der;
			free(hoja);
			return p;
		}
		else if (hoja->der == NULL) {
			p = hoja->izq;
			free(hoja);
			return p;
		}
		else {
			p = hoja->izq;
			p2 = hoja->izq;
			while (p->der) p = p->der;
			p->der = hoja->der;
			free(hoja);
			return p2;
		}
	}
	else if (num<hoja->dato)
		hoja->izq = borrari(hoja->izq, num);
	else
		hoja->der = borrari(hoja->der, num);
	return hoja;
}

struct arbol *podar(struct arbol *hoja) {
	if (!hoja) return hoja;

	podar(hoja->izq);
	podar(hoja->der);
	free(hoja);
	hoja = NULL;
	return hoja;
}

/*Recorridos*/
void preorden(struct arbol *hoja) {
	if (!hoja) return;

	printf("%i ", hoja->dato);
	preorden(hoja->izq);
	preorden(hoja->der);
}

void inorden(struct arbol *hoja) {
	if (!hoja) return;

	inorden(hoja->izq);
	printf("%i ", hoja->dato);
	inorden(hoja->der);
}

void posorden(struct arbol *hoja) {
	if (!hoja) return;

	posorden(hoja->izq);
	posorden(hoja->der);
	printf("%i ", hoja->dato);
}

int contarHojas(struct arbol *arbol)
{
	if (arbol == NULL)
	{
		return 0;
	}
	if ((arbol->der == NULL) && (arbol->izq == NULL))
	{
		return 1;
	}
	else
	{
		return contarHojas(arbol->izq) + contarHojas(arbol->der);
	}
}
/*Menus del Arbol*/
void menu_recorridos(void) {
	char _op = 'S';

	while (_op != '4') {
		system("cls");
		printf("\n\n\t\tMenu Recorridos.");
		printf("\n\t1. PreOrden.");
		printf("\n\t2. InOrden.");
		printf("\n\t3. PosOrden.");
		printf("\n\t4. Salir.");
		printf("\n\n\tIngrese Una Opcion: ");
		_op = _getch();
		switch (_op) {
		case '1':
			preorden(raiz);
			_getch();
			break;
		case '2':
			inorden(raiz);
			_getch();
			break;
		case '3':
			posorden(raiz);
			_getch();
			break;
		}
	}
	return;
}

void menu_busquedas(void) {
	int val;
	system("cls");
	printf("\n\t\tMenu Busquedas.");
	printf("\n\n\tNumero: ");
	scanf_s("\t%i", &val);
	if (busqueda(raiz, val))
		printf("\n\n\tEncontrado...");
	else printf("\n\n\tError, No se encuentra.");
	_getch();
}

void menu_alturas(void) {
	char _op = 'A';
	int val, altura;

	while (_op != '4') {
		system("cls");
		printf("\n\n\t\tMenu Alturas.");
		printf("\n\t1. Altura de Un Nodo (Profundidad). ");
		printf("\n\t2. Altura de Todo el Arbol.");
		printf("\n\t3. Informacion de un nodo.");
		printf("\n\t4. Salir.");
		printf("\n\n\tIngrese Una Opcion: ");
		_op = _getch();
		switch (_op) {
		case '1':
			printf("\n\n\tNumero: ");
			scanf_s("\t%i", &val);
			altura = alturax(raiz, val);
			if (!altura) printf("\n\n\tImposible, el numero no existe.");
			else printf("\n\n\tLa Altura es: %i", altura);
			_getch();
			break;
		case '2':
			altura = 0;
			printf("\n\n\tLa Altura del Arbol es: %i", alturafull(raiz, &altura));
			_getch();
			break;
		case '3':
			printf("\n\n\tNumero: ");
			scanf_s("\t%i", &val);
			if (!busqueda(raiz, val)) printf("\n\n\tImposible, el numero no existe.");
			else {
				Fe(raiz, val);
			}
			_getch();
			break;
		}
	}
	return;
}

void menu_nodos(void) {
	struct arbol *aux = raiz;
	system("cls");
	printf("\n\n\t\tMenu Nodos.");
	printf("\n\n\tEl Numero de Nodos es: %i", nodos(raiz));
	printf("\n\tLa Suma de los Nodos es: %i", sumnodos(raiz));
	printf("\n\tEl Numero de Hojas es: %i", contarHojas(aux));
	_getch();
}

void menu_podar(void) {
	char _op = 'A';
	char op = 'A';
	int val;

	while (_op != '3') {
		system("cls");
		printf("\n\n\t\tMenu Podar.");
		printf("\n\t1. Podar Un Nodos del Arbol.");
		printf("\n\t2. Podar Todo el Arbol.");
		printf("\n\t3. Salir.");
		_op = _getch();
		switch (_op) {
		case '1':
			while (op != '3') {
				system("cls");
				cout << "\t\tmenu podar:\n";
				cout << "\t1. Borrar por la derecha\n";
				cout << "\t2. Borrar por la izquierda\n";
				cout << "\t3. Salir\n";
				op = _getch();
				switch (op) {
				case '1':
					printf("\n\n\tNumero: ");
					scanf_s("\t%i", &val);
					if (!busqueda(raiz, val)) break;
					raiz = borrarx(raiz, val);
					printf("\n\n\t.... Borrado ....");
					break;
				case '2':
					printf("\n\n\tNumero: ");
					scanf_s("\t%i", &val);
					if (!busqueda(raiz, val)) break;
					raiz = borrari(raiz, val);
					printf("\n\n\t.... Borrado ....");
					break;
				}
			}
			break;
		case '2':
			raiz = podar(raiz);
			printf("\n\n\tArbol Borrado por Completo.");
			_getch();
			break;
		}
	}
	return;
}

int main9() {
	char _op = 'A';
	int val;

	inicializar();

	while (_op != '7') {
		system("cls");
		printf("\n\t\tMenu.");
		printf("\n\t1. Insertar.");
		printf("\n\t2. Recorridos.");
		printf("\n\t3. Busquedas.");
		printf("\n\t4. Alturas.");
		printf("\n\t5. Nodos.");
		printf("\n\t6. Podar.");
		printf("\n\t7. Salir.");
		printf("\n\n\tIngrese Una Opcion: ");
		_op = toupper(_getch());
		switch (_op) {
		case '1':
			printf("\n\n\tNumero: ");
			scanf_s("%i", &val);
			if (busqueda(raiz, val)) {
				printf("\n\n\tEste numero ya ha sido insertado.");
				_getch();
				break;
			}
			raiz = insertar(raiz, raiz, val);
			break;
		case '2':
			if (vacio(raiz)) {
				printf("\n\n\tEl Arbol Aun esta Vacio.");
				_getch();
				break;
			}
			menu_recorridos();
			break;
		case '3':
			if (vacio(raiz)) {
				printf("\n\n\tEl Arbol Aun esta Vacio.");
				_getch();
				break;
			}
			menu_busquedas();
			break;
		case '4':
			if (vacio(raiz)) {
				printf("\n\n\tEl Arbol Aun esta Vacio.");
				_getch();
				break;
			}
			menu_alturas();
			break;
		case '5':
			if (vacio(raiz)) {
				printf("\n\n\tEl Arbol Aun esta Vacio.");
				_getch();
				break;
			}
			menu_nodos();
			break;
		case '6':
			if (vacio(raiz)) {
				printf("\n\n\tEl Arbol Aun esta Vacio.");
				_getch();
				break;
			}
			menu_podar();
			break;
		}
	}
	printf("\n\n\tPulsa para salir...");
	system("pause>NULL");
	getchar();
	return 0;
}