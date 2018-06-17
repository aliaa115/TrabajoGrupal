#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

///variables glovales
int Dato_HashN, SDato_HashN, Max_HashN = 5;

///estructuras
struct llave_HashN {
	struct llave_HashN *s_HashN;
	struct llave_HashN *a_HashN;
	int lla_HashN;
}*inicioL_HashN, *finL_HashN, *recorrerL_HashN, *nuevoL_HashN;

struct clave_HashN {
	struct clave_HashN *a_HashN;
	struct clave_HashN *s_HashN;
	int cla_HashN;
	struct llave_HashN *llave_HashN;
}*inicioC_HashN, *finC_HashN, *recorrerC_HashN, *nuevoC_HashN;

///prototipos:
clave_HashN *nuevaC_HashN();
llave_HashN *nuevaL_HashN();
llave_HashN *recoL_HashN(clave_HashN*);
clave_HashN *recoC_HashN();
int funHash_HashN();
void inicC_HashN();
void iniciarClave_HashN();
llave_HashN *buscarLlave_HashN(int);
void insertarLlave_HashN(clave_HashN*);
void irEnLlave_HashN();
void pedirDato_HashN();
void imprimir_HashN();
void elim_HashN();
void buscar_HashN();


clave_HashN *nuevaC_HashN() {
	nuevoC_HashN = new clave_HashN;
	if (nuevoC_HashN) {
		nuevoC_HashN->s_HashN = NULL;
		nuevoC_HashN->cla_HashN = 0;
		nuevoC_HashN->a_HashN = NULL;
		nuevoC_HashN->llave_HashN = NULL;
	}
	return nuevoC_HashN;
}

llave_HashN *nuevaL_HashN() {
	nuevoL_HashN = new llave_HashN;
	if (nuevoL_HashN) {
		nuevoL_HashN->s_HashN = NULL;
		nuevoL_HashN->a_HashN = NULL;
		nuevoL_HashN->lla_HashN = NULL;
	}
	return nuevoL_HashN;
}

int funHash_HashN() {
	return (Dato_HashN % Max_HashN);
}


void inicC_HashN() {
	inicioC_HashN = nuevaC_HashN();
	inicioC_HashN->cla_HashN = 0;
	cout << "\n\tINGRESE LA LLAVE LA POSICION 0: ";
	cin  >> inicioC_HashN->cla_HashN;
}

clave_HashN *recoC_HashN() {
	recorrerC_HashN = inicioC_HashN;
	while (recorrerC_HashN->s_HashN) {
		recorrerC_HashN = recorrerC_HashN->s_HashN;
	}
	return recorrerC_HashN;
}

llave_HashN *recoL_HashN(llave_HashN *i_HashN) {
	recorrerL_HashN = i_HashN;
	while (recorrerL_HashN->s_HashN) {
		recorrerL_HashN = recorrerL_HashN->s_HashN;
	}
	return recorrerL_HashN;
}

void iniciarClave_HashN() {
	clave_HashN *n, *aux;
	for (int i = 0; i < Max_HashN; i++) {
		if (!inicioC_HashN)inicC_HashN();
		else {
			n = nuevaC_HashN();
			aux = recoC_HashN();
			n->cla_HashN = i;
			cout << "\n\tCLAVE " << i << " INGRESADA. ";
			aux->s_HashN = n;
			n->a_HashN = aux;
		}
	}
}
