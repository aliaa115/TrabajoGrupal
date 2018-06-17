#pragma once

#include <iostream>
#include <string>
#include "Hash_N.h"
#include "Lista_Doble.h"
//#include "Lista_Simple.h"

void menu(std::string opcion) {
	int st = atoi(opcion.c_str());
	switch (st){
	case 1:
		break;
	case 2:
		break;
	case 3:
		//main3();
		break;
	case 4:
		main4();
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		main7();
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		break;
	}
}