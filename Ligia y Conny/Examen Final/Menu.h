#pragma once

#include <iostream>
#include <string>
#include "Hash_N.h"
#include "Hash_L.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista_Circular.h"
#include "Lista_Doble.h"
#include "Lista_Simple.h"
#include "floyd.h"
#include "ArbolesAVL.h"
#include "ArbolesBinariosDeBusqueda.h"

void menu(std::string opcion) {
	int st = atoi(opcion.c_str());
	switch (st){
	case 1:
		main1();
		break;
	case 2:
		break;
	case 3:

		break;
	case 4:
		main4();
		break;
	case 5:
		main5();
		break;
	case 6:
		main6();
		break;
	case 7:
		main7();
		break;
	case 8:
		main8();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		break;
	case 9:
		main9();
		break;
	case 10:
		main10();
		break;
	default:
		break;
	}
}