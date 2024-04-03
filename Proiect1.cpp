#include "include\listaplata.h"
#include <iostream>
#include <vector>

enum Optiune {
	OPT_AFISARE,
	OPT_MODIFIC_LOCATAR,
	OPT_STERG_LOCATAR,
	OPT_STERG_FACTURA,
	OPT_ADAUGARE,
	OPT_IESI
};
int main()
{
	lista_plata LP;
	std::cin >> LP;
	LP.calcul_lista_plata();
	while (1) {
		int optiune;
		std::cout << "Ce vrei sa faci acum? \n[0] afisez_lista \n[1] modific_info_locatar\n[2] sterg_locatar\n[3] sterg_factura\n[4] adaugare_facturi_si_locatari\n[5] iesi\n";
		std::cin >> optiune;
		if (optiune != OPT_IESI)
		{
			switch (optiune){
			case OPT_AFISARE:
			{
				std::cout << LP;
				break; 
			}
			case OPT_MODIFIC_LOCATAR:{
				std::string NumeLocatar;
				std::cout << "Al cui locatar?";
				std::cin >> NumeLocatar;
				LP > NumeLocatar;
				break; 
			}
			case OPT_STERG_LOCATAR:{
				std::string NumeLocatar;
				std::cout << "Care locatar?";
				std::cin >> NumeLocatar;
				LP.stergereLocatar(NumeLocatar);
				break;
			}
			case OPT_STERG_FACTURA:{
				std::string NumeFactura;
				std::cout << "Care factura?";
				std::cin >> NumeFactura;
				LP.stergereFactura(NumeFactura);
				break; 
			}
			case OPT_ADAUGARE:{
				std::cin >> LP;
				break;
			}}
			LP.calcul_lista_plata();
		}
		else 
			break;
	}
}

