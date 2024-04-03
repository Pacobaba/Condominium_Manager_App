#include "listaplata.h"
#include <iostream>
#include <vector>

int main()
{
	lista_plata LP;
	std::cin >> LP;
	LP.calcul_lista_plata();
	while (1) {
		std::string optiune;
		std::cout << "Ce vrei sa faci acum? \n- afisez_lista\n- modific_info_locatar\n- sterg_locatar\n- sterg_factura\n- adaugare_facturi_si_locatari\n- iesi\n";
		std::cin >> optiune;
		if (optiune != "iesi")
		{
			if (optiune == "afisez_lista")
				std::cout << LP;
			if (optiune == "modific_info_locatar")
			{
				std::cout << "Al cui locatar?";
				std::cin >> optiune;
				LP > optiune;
			}
			if (optiune == "sterg_locatar")
			{
				std::cout << "Care locatar?";
				std::cin >> optiune;
				LP.stergereLocatar(optiune);
			}
			if (optiune == "sterg_factura")
			{
				std::cout << "Care factura?";
				std::cin >> optiune;
				LP.stergereFactura(optiune);
			}
			if (optiune == "adaugare_facturi_si_locatari")
			{
				std::cin >> LP;
			}
			LP.calcul_lista_plata();
		}
		else 
			break;
	}
}

