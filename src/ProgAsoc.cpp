#include "..\include\ProgAsoc.h"
#include <iostream>

void ProgAsoc::Run(lista_plata& LP) {
	enum Optiune {
		OPT_AFISARE,
		OPT_AFISARE_ANGAJATI,
		OPT_ADAUGARE,
		OPT_ADAUGARE_ANGAJAT,
		OPT_MODIFIC_LOCATAR,
		OPT_MODIFIC_ANGAJAT,
		OPT_STERG_LOCATAR,
		OPT_STERG_FACTURA,
		OPT_STERG_ANGAJAT,
		OPT_IESI,
	};
	LP.calcul_lista_plata();
	bool Terminat = 0;
	while (!Terminat) {
		try{
			int optiune;
			std::cout << "\n\n\nCe vrei sa faci acum? \n[0] afisez_lista \n[1] afisez_lista_angajati\n[2] adaugare_facturi_si_locatari\n[3] adaugare_angajati\n[4] modific_info_locatar\n[5] modific_info_angajat\n[6] sterg_locatar\n[7] sterg_factura\n[8] sterg_angajat\n[9] iesi\n";
			std::cin >> optiune;
			if (optiune != OPT_IESI) {
				switch (optiune) {
				case OPT_AFISARE: {
					std::cout << LP;
					break;
				}
				case OPT_MODIFIC_LOCATAR: {
					std::string NumeLocatar;
					std::cout << "Al cui locatar?";
					std::cin >> NumeLocatar;
					LP.modificare("locatar", NumeLocatar);
					break;
				}
				case OPT_STERG_LOCATAR: {
					std::string NumeLocatar;
					std::cout << "Care locatar?";
					std::cin >> NumeLocatar;
					LP.stergere("locatari", NumeLocatar);
					break;
				}
				case OPT_STERG_FACTURA: {
					std::string NumeFactura;
					std::cout << "Care factura?";
					std::cin >> NumeFactura;
					LP.stergere("facturi", NumeFactura);
					break;
				}
				case OPT_ADAUGARE: {
					std::cin >> LP;
					break;
				}
				case OPT_MODIFIC_ANGAJAT: {
					std::string NumeAngajat;
					std::cout << "Care angajat?";
					std::cin >> NumeAngajat;
					LP.modificare("angajat", NumeAngajat);
					break;
				}
				case OPT_ADAUGARE_ANGAJAT: {
					angajat AngTemp;
					std::cin >> AngTemp;
					LP.adaugareAngajat(AngTemp);
					break;
				}
				case OPT_STERG_ANGAJAT: {
					std::string NumeAngajat;
					std::cout << "Care angajat?";
					std::cin >> NumeAngajat;
					LP.stergere("angajat", NumeAngajat);
					break; }
				case OPT_AFISARE_ANGAJATI: {
					LP.afisareAngajati();
				}
				}
				LP.calcul_lista_plata();
			}
			else
				Terminat = 1;
		}
		catch (const std::runtime_error& eroare){
			std::cout << eroare.what() << std::endl;
		}
	}
}

void ProgAsoc::ColectiePersoane(std::vector<locatar> Loc, std::vector<angajat> Ang){
	std::vector<persoana*> Toti;
	for (int i = 0; i < Loc.size() + Ang.size(); i++)
	{
		int i0 = 0;
		if (i >= i0 && i < i0 + Loc.size())
		{
			Toti.push_back(dynamic_cast<persoana*>(&Loc[i-i0]));
		}
		else
		{		
			i0 = Loc.size();
			if (i >= i0 && i < i0+Ang.size())
				Toti.push_back(dynamic_cast<persoana*>(&Ang[i - i0]));
		}
	}
	for (int i = 0; i < Toti.size(); i++)
	{
		if(dynamic_cast<locatar*>(Toti[i])!=nullptr)
			std::cout << *dynamic_cast<locatar*>(Toti[i]) << "\n";
		if (dynamic_cast<angajat*>(Toti[i]) != nullptr)
			std::cout << *dynamic_cast<angajat*> (Toti[i]) << "\n";
	}
}