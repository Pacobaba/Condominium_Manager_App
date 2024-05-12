#include "include\ProgAsoc.h"
#include <iostream>

int main()
{

	lista_plata LP;
	std::cin >> LP;
	ProgAsoc::Run(LP);
	std::vector<locatar> Loc = {locatar("Bob",1,2.3f),locatar("Ana",1,3.0f)};
	std::vector<angajat> Ang = {angajat("Bab","Sef",300)};

	ProgAsoc::ColectiePersoane(Loc, Ang);
}

