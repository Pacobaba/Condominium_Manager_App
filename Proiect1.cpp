#include "listaplata.h"
#include <iostream>

int main()
{
	lista_plata LP;
	std::cin >> LP;
	LP.calcul_lista_plata();
	LP.afisare();
}

