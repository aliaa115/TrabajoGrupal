#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

int nodD[100][100];
int nodS[100][100];

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}

void impBasMat(int n, int x, int y, char c, int t, int cont) {
	if (t == 1) if (cont == 4 * n) return;
	if (t == 0) if (cont == 2 * n) return;
	if (t == 1)gotoxy(x - 3, y);
	if (t == 0) { gotoxy(x, y - 1); }
	cout << c;

	if (t == 1) {
		if (cont == 0)impBasMat(n, x + 1, y, '-', 1, cont + 1);
		else impBasMat(n, x + 1, y, '-', 1, cont + 1);
	}
	if (t == 0) {
		if (cont % 2 == 0) {
			impBasMat(n, x, y + 1, '-', 0, cont + 1);
		}
		else
			impBasMat(n, x, y + 1, '|', 0, cont + 1);
	}
}

void imprimirNumPes(int n, int a) {
	if (a == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		for (int i = 0; i < (n + 1); i++)
			impBasMat(n + 1, 9, 6 + (i * 2), '-', 1, 0);
		for (int i = 0; i < ((n + 1) * 4); i = i + 4)
			impBasMat(n + 1, 9 + i, 6, '|', 0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		for (int i = 0; i < (n); i++) {
			gotoxy(10 + (i * 4), 5);
			cout << i + 1;
		}
		for (int i = 0; i < n; i++) {
			gotoxy(6, 7 + (i * 2));
			cout << i + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int dato;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					gotoxy(10 + (i * 4), 7 + (j * 2));
					cin >> dato;
					nodD[i][j] = dato;
					nodS[i][j] = i + 1;
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					gotoxy(10 + (i * 4), 7 + (j * 2));
					nodD[i][j] = -2;
					nodS[i][j] = -2;
					cout << " -";
				}
			}
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		for (int i = 0; i < (n + 1); i++)
			impBasMat(n + 1, 9, 6 + (i * 2), '-', 1, 0);
		for (int i = 0; i < ((n + 1) * 4); i = i + 4)
			impBasMat(n + 1, 9 + i, 6, '|', 0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		for (int i = 0; i < (n); i++) {
			gotoxy(10 + (i * 4), 5);
			cout << i + 1;
		}
		for (int i = 0; i < n; i++) {
			gotoxy(6, 7 + (i * 2));
			cout << i + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int dato;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					gotoxy(10 + (i * 4), 7 + (j * 2));
					cout << nodD[i][j];
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					gotoxy(10 + (i * 4), 7 + (j * 2));
					cout << " -";
				}
			}
		}
	}
}

void limpiarMat(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int dato;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(10 + (i * 4), 7 + (j * 2));
				cout << "   ";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(10 + (i * 4), 7 + (j * 2));
				cout << " -";
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(10 + (i * 4), 7 + (j * 2) + (n * 2) + 3);
				cout << "   ";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(10 + (i * 4), 7 + (j * 2) + (n * 2) + 3);
				cout << " -";
			}
		}
	}
}

void imprimirNumEst(int n) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	for (int i = 0; i < (n + 1); i++)
		impBasMat(n + 1, 9, 6 + (n * 2) + (i * 2) + 3, '-', 1, 0);
	for (int i = 0; i < ((n + 1) * 4); i = i + 4)
		impBasMat(n + 1, 9 + i, 6 + (n * 2) + 3, '|', 0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	for (int i = 0; i < (n); i++) {
		gotoxy(10 + (i * 4), 5 + (n * 2) + 3);
		cout << i + 1;
	}
	for (int i = 0; i < n; i++) {
		gotoxy(6, 7 + (i * 2) + (n * 2) + 3);
		cout << i + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(10 + (i * 4), 7 + (j * 2) + (n * 2) + 3);
				cout << nodS[i][j];
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(10 + (i * 4), 7 + (j * 2) + (n * 2) + 3);
				cout << " -";
			}
		}
	}
}

void calculo(int f, int n) {
	system("cls");
	cout << "\n\n\t\t\t.:OPERACIONES DE LA MATRIZ:.";
	if (f == n + 1)return;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(4, 5); cout << "D_" << f;
	gotoxy(4, 5 + (n * 2) + 3); cout << "S_" << f;
	int nodDAux[100][100];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			nodDAux[i][j] = nodD[i][j];
	//=SI(Y($G25="><";H$23="><");H17;SI(O(H$23="><";$G25="><");H17;SI((H$23+$G25)<H17;$G25+H$23;H17)))

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int k = f - 1;
				gotoxy(70 + i * 3, j + 20); cout << "         ";
				if (j != k) {
					if (i != k) {
						if (nodD[i][k] == -1) {
							nodDAux[i][j] = nodD[i][j];
						}
						else if (nodD[k][j] == -1) {
							nodDAux[i][j] = nodD[i][j];
						}
						else if (nodD[i][j] == -1) {
							nodDAux[i][j] = nodD[i][k] + nodD[k][j];
							nodS[i][j] = f;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							gotoxy(70 + i * 3, j + 20); cout << "( " << nodD[i][j] << " )";
						}
						else if ((nodD[i][k] + nodD[k][j]) < nodD[i][j]) {
							nodDAux[i][j] = nodD[i][k] + nodD[k][j];
							nodS[i][j] = f;
						}
						else if ((nodD[i][k] + nodD[k][j]) < nodD[i][j]) nodDAux[i][j] = nodD[i][j];
					}
				}
			}
		}
	}

	gotoxy(0, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << nodD[i][j] << " ";
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			nodD[i][j] = nodDAux[i][j];
	cout << "\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << nodDAux[i][j] << " ";
	limpiarMat(n);
	imprimirNumPes(n, 0);
	imprimirNumEst(n);
	_getch();
	calculo(f + 1, n);
}

void main8() {
	system("cls");
	int n;
	cout << "\n\n\t\t\t.:INGRESO DE DATOS:. \n\t\t::Numero de filas: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(5, 4); cout << "se recomienda usar matrices menores a 6 filas para mejor visualizacion...";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(35, 3); cin >> n;
	gotoxy(4, 5); cout << "D_0";
	imprimirNumPes(n, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(4, 5 + (n * 2) + 3); cout << "S_0";
	imprimirNumEst(n);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "\n\n\n\tPRECIONE UNA TECLA PARA CONTICUALR CON LOS CALCULOS...";
	_getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	calculo(1, n);
	gotoxy(0, 5);
	_getch();
}

