#pragma once
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>

enum { IZQUIERDO, DERECHO };

typedef struct _nodo {
	int dato;
	int FE;
	struct _nodo *derecho;
	struct _nodo *izquierdo;
	struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;
void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);
void InOrden(Arbol, void(*func)(int*));
void PreOrden(Arbol, void(*func)(int*));
void PostOrden(Arbol, void(*func)(int*));
void Equilibrar(Arbol *raiz, pNodo nodo, int, int);
void RSI(Arbol *raiz, pNodo nodo);
void RSD(Arbol *raiz, pNodo nodo);
void RDI(Arbol *raiz, pNodo nodo);
void RDD(Arbol *raiz, pNodo nodo);
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);
void Mostrar(int *d);

int main10() {
	Arbol ArbolInt = NULL;
	int altura;
	int nnodos;

	Insertar(&ArbolInt, 10);
	Insertar(&ArbolInt, 5);
	Insertar(&ArbolInt, 12);
	Insertar(&ArbolInt, 4);
	Insertar(&ArbolInt, 7);
	Insertar(&ArbolInt, 3);
	Insertar(&ArbolInt, 6);
	Insertar(&ArbolInt, 9);
	Insertar(&ArbolInt, 8);
	Insertar(&ArbolInt, 11);
	Insertar(&ArbolInt, 14);
	Insertar(&ArbolInt, 13);
	Insertar(&ArbolInt, 2);
	Insertar(&ArbolInt, 1);
	Insertar(&ArbolInt, 15);
	Insertar(&ArbolInt, 10);
	Insertar(&ArbolInt, 17);
	Insertar(&ArbolInt, 18);
	Insertar(&ArbolInt, 16);
	printf("Altura de arbol: %d\n", AlturaArbol(ArbolInt, &altura));

	printf("InOrden: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	printf("PreOrden: ");
	PreOrden(ArbolInt, Mostrar);
	printf("\n");
	printf("PostOrden: ");
	PostOrden(ArbolInt, Mostrar);
	printf("\n");

	printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
	Borrar(&ArbolInt, 5);
	printf("Borrar 5: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	Borrar(&ArbolInt, 8);
	printf("Borrar 8: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	Borrar(&ArbolInt, 15);
	printf("Borrar 15: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	Borrar(&ArbolInt, 245);
	printf("Borrar 245: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	Borrar(&ArbolInt, 4);
	printf("Borrar 4: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");
	Borrar(&ArbolInt, 17);
	printf("Borrar 17: ");
	InOrden(ArbolInt, Mostrar);
	printf("\n");

	printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
	printf("Altura de 1: %d\n", Altura(ArbolInt, 1));
	printf("Altura de 10: %d\n", Altura(ArbolInt, 10));
	printf("Altura de arbol: %d\n", AlturaArbol(ArbolInt, &altura));

	Podar(&ArbolInt);
	system("PAUSE");
	return 0;
}

void Podar(Arbol *a) {
	if (*a) {
		Podar(&(*a)->izquierdo);
		Podar(&(*a)->derecho);
		free(*a);
		*a = NULL;
	}
}

void Insertar(Arbol *a, int dat) {
	pNodo padre = NULL;
	pNodo actual = *a;

	while (!Vacio(actual) && dat != actual->dato) {
		padre = actual;
		if (dat < actual->dato) actual = actual->izquierdo;
		else if (dat > actual->dato) actual = actual->derecho;
	}

	if (!Vacio(actual)) return;

	if (Vacio(padre)) {
		*a = (Arbol)malloc(sizeof(tipoNodo));
		(*a)->dato = dat;
		(*a)->izquierdo = (*a)->derecho = NULL;
		(*a)->padre = NULL;
		(*a)->FE = 0;
	}
	else if (dat < padre->dato) {
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->izquierdo = actual;
		actual->dato = dat;
		actual->izquierdo = actual->derecho = NULL;
		actual->padre = padre;
		actual->FE = 0;
		Equilibrar(a, padre, IZQUIERDO, TRUE);
	}
	else if (dat > padre->dato) {
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->derecho = actual;
		actual->dato = dat;
		actual->izquierdo = actual->derecho = NULL;
		actual->padre = padre;
		actual->FE = 0;
		Equilibrar(a, padre, DERECHO, TRUE);
	}
}

void Equilibrar(Arbol *a, pNodo nodo, int rama, int nuevo) {
	int salir = FALSE;
	while (nodo && !salir) {
		if (nuevo)
			if (rama == IZQUIERDO) nodo->FE--;
			else nodo->FE++;
		else
			if (rama == IZQUIERDO) nodo->FE++;
			else nodo->FE--;
			if (nodo->FE == 0) salir = TRUE;
			else if (nodo->FE == -2) {
				if (nodo->izquierdo->FE == 1) RDD(a, nodo);
				else RSD(a, nodo);
				salir = TRUE;
			}
			else if (nodo->FE == 2) {
				if (nodo->derecho->FE == -1) RDI(a, nodo);
				else RSI(a, nodo);
				salir = TRUE;
			}
			if (nodo->padre)
				if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
			nodo = nodo->padre;
	}
}

void RDD(Arbol *raiz, Arbol nodo) {
	pNodo Padre = nodo->padre;
	pNodo P = nodo;
	pNodo Q = P->izquierdo;
	pNodo R = Q->derecho;
	pNodo B = R->izquierdo;
	pNodo C = R->derecho;
	if (Padre)
		if (Padre->derecho == nodo) Padre->derecho = R;
		else Padre->izquierdo = R;
	else *raiz = R;

	Q->derecho = B;
	P->izquierdo = C;
	R->izquierdo = Q;
	R->derecho = P;

	R->padre = Padre;
	P->padre = Q->padre = R;
	if (B) B->padre = Q;
	if (C) C->padre = P;

	switch (R->FE) {
	case -1: Q->FE = 0; P->FE = 1; break;
	case 0: Q->FE = 0; P->FE = 0; break;
	case 1: Q->FE = -1; P->FE = 0; break;
	}
	R->FE = 0;
}

void RDI(Arbol *a, pNodo nodo) {
	pNodo Padre = nodo->padre;
	pNodo P = nodo;
	pNodo Q = P->derecho;
	pNodo R = Q->izquierdo;
	pNodo B = R->izquierdo;
	pNodo C = R->derecho;
	if (Padre)
		if (Padre->derecho == nodo) Padre->derecho = R;
		else Padre->izquierdo = R;
	else *a = R;

	P->derecho = B;
	Q->izquierdo = C;
	R->izquierdo = P;
	R->derecho = Q;

	R->padre = Padre;
	P->padre = Q->padre = R;
	if (B) B->padre = P;
	if (C) C->padre = Q;

	switch (R->FE) {
	case -1: P->FE = 0; Q->FE = 1; break;
	case 0: P->FE = 0; Q->FE = 0; break;
	case 1: P->FE = -1; Q->FE = 0; break;
	}
	R->FE = 0;
}

void RSD(Arbol *a, pNodo nodo) {
	pNodo Padre = nodo->padre;
	pNodo P = nodo;
	pNodo Q = P->izquierdo;
	pNodo B = Q->derecho;
	if (Padre)
		if (Padre->derecho == P) Padre->derecho = Q;
		else Padre->izquierdo = Q;
	else *a = Q;

	P->izquierdo = B;
	Q->derecho = P;

	P->padre = Q;
	if (B) B->padre = P;
	Q->padre = Padre;

	P->FE = 0;
	Q->FE = 0;
}

void RSI(Arbol *a, pNodo nodo) {
	pNodo Padre = nodo->padre;
	pNodo P = nodo;
	pNodo Q = P->derecho;
	pNodo B = Q->izquierdo;
	if (Padre)
		if (Padre->derecho == P) Padre->derecho = Q;
		else Padre->izquierdo = Q;
	else *a = Q;

	P->derecho = B;
	Q->izquierdo = P;

	P->padre = Q;
	if (B) B->padre = P;
	Q->padre = Padre;

	P->FE = 0;
	Q->FE = 0;
}

void Borrar(Arbol *a, int dat) {
	pNodo padre = NULL;
	pNodo actual;
	pNodo nodo;
	int aux;
	actual = *a;

	while (!Vacio(actual)) {
		if (dat == actual->dato) {
			if (EsHoja(actual)) {
				if (padre)
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
					free(actual);
					actual = NULL;
					if ((padre->derecho == actual && padre->FE == 1) ||
						(padre->izquierdo == actual && padre->FE == -1)) {
						padre->FE = 0;
						actual = padre;
						padre = actual->padre;
					}
					if (padre)
						if (padre->derecho == actual) Equilibrar(a, padre, DERECHO, FALSE);
						else Equilibrar(a, padre, IZQUIERDO, FALSE);
						return;
			}
			else {
				padre = actual;
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else {
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

void InOrden(Arbol a, void(*func)(int*)) {
	if (a->izquierdo) InOrden(a->izquierdo, func);
	func(&(a->dato));
	if (a->derecho) InOrden(a->derecho, func);
}

void PreOrden(Arbol a, void(*func)(int*)) {
	func(&a->dato);
	if (a->izquierdo) PreOrden(a->izquierdo, func);
	if (a->derecho) PreOrden(a->derecho, func);
}

void PostOrden(Arbol a, void(*func)(int*)) {
	if (a->izquierdo) PostOrden(a->izquierdo, func);
	if (a->derecho) PostOrden(a->derecho, func);
	func(&a->dato);
}

int Buscar(Arbol a, int dat) {
	pNodo actual = a;

	while (!Vacio(actual)) {
		if (dat == actual->dato) return TRUE;
		else if (dat < actual->dato) actual = actual->izquierdo;
		else if (dat > actual->dato) actual = actual->derecho;
	}
	return FALSE;
}

int Altura(Arbol a, int dat) {
	int altura = 0;
	pNodo actual = a;

	while (!Vacio(actual)) {
		if (dat == actual->dato) return altura;
		else {
			altura++;
			if (dat < actual->dato) actual = actual->izquierdo;
			else if (dat > actual->dato) actual = actual->derecho;
		}
	}
	return -1;
}

int NumeroNodos(Arbol a, int *contador) {
	*contador = 0;
	auxContador(a, contador);
	return *contador;
}

void auxContador(Arbol nodo, int *c) {
	(*c)++;
	if (nodo->izquierdo) auxContador(nodo->izquierdo, c);
	if (nodo->derecho) auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol a, int *altura) {
	*altura = 0;
	auxAltura(a, 0, altura);
	return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura) {
	if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1, altura);
	if (nodo->derecho) auxAltura(nodo->derecho, a + 1, altura);
	if (EsHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(Arbol r) {
	return r == NULL;
}

int EsHoja(pNodo r) {
	return !r->derecho && !r->izquierdo;
}

void Mostrar(int *d) {
	printf("%d, ", *d);
}