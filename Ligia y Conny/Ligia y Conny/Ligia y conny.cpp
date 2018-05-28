#include <iostream>
#include <conio.h>

using namespace std;

///=======PROTOTIPOS=======
void programa1();


///=======FUNCION MAIN=======

void main() {
	cout << "\t\tPROYECTO CON GITHUB Y HITKRAKEN DE PROGRAMACION 3\n\n";

	programa1();
}


///Programa 1
	//Rombo de *
void programa1() {
	system("cls");
	
	int n;
	cout << "\n\n\t\tROMBO DE ASTERISCOS:\n";
	cout << "\tINGRESE LA ALTURA DEL ROMBO:  "; cin >> n;

	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << "\t";
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << "*";
		} cout << "\n";
	}
	for (int i = n - 2; i >= 0; i--) {
		cout << "\t";
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n\n";
	_getch();

}