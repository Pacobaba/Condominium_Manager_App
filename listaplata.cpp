#include "include\listaplata.h"
#include <string>
int lista_plata::cautareLocatar(std::string NumeLocatar)
{
	for (int i = 0; i < lista_locatari.size(); i++)
		if (lista_locatari[i].get_nume() == NumeLocatar)
			return i;
}

int lista_plata::cautareFactura(std::string NumeFactura)
{
	for (int i = 0; i < Facturi.size(); i++)
		if (Facturi[i].get_nume() == NumeFactura)
			return i;
}

std::string lista_plata::completare(std::string sir_initial, int nr_max_caractere)
{
	std::string temp = "";
	for (int j = sir_initial.size(); j < nr_max_caractere; j++)
		temp += " ";
	return temp+sir_initial;
}



lista_plata::lista_plata(std::vector<locatar> listaloc, std::vector<factura> Fact) {
	for (int i = 0; i < listaloc.size(); i++)
		lista_locatari[i] = listaloc[i];
	if (Fact.size() > 0)
		for (int i = 0; i < Fact.size(); i++)
			Facturi[i] = Fact[i];
	else
	{
		Facturi.push_back(factura("ApaRece"));
		Facturi.push_back(factura("Curent"));
		Facturi.push_back(factura("Caldura"));
	}
}

std::istream& operator>>(std::istream& is, lista_plata& LP)
{
	int length = LP.lista_locatari.size();
	if (nr_ap - length > 0)
		std::cout << "Se vor citi " << nr_ap - length << " locatari de la tastatura\n";
	for (int i = length; i < nr_ap; i++)
	{
		locatar locatartemporar = locatar("", i);
		std::cout << "Al " << i + 1 << "-lea locatar: \n";
		is >> locatartemporar;
		LP.lista_locatari.push_back(locatartemporar);
	}
	char ok;
	std::cout << "Exista alte facturi decat cele 3 standard? (Y/N)";
	is >> ok;
	length = LP.Facturi.size();
	int x = 0;
	if (ok == 'Y')
	{
		std::cout << "Cate alte facturi mai sunt? ";
		is >> x;
	}
	for (int i = 0; i < length + x; i++)
	{
		if (i >= 0 && i <= 2)
			is >> LP.Facturi[i];
		else
		{
			factura factura_temp;
			is >> factura_temp;
			LP.Facturi.push_back(factura_temp);
		}

	}
	return is;
}

std::ostream& operator<<(std::ostream& os, lista_plata& LP)
{
	int MaxChrSize = 0;
	for (int i = 0; i < LP.lista_locatari.size(); i++)
		if (MaxChrSize < LP.lista_locatari[i].get_nume().size())
			MaxChrSize = LP.lista_locatari[i].get_nume().size();
	for (int i = 0; i < LP.Facturi.size(); i++)
		if (MaxChrSize < LP.Facturi[i].get_nume().size())
			MaxChrSize = LP.Facturi[i].get_nume().size();
	int nr_loc = LP.lista_locatari.size(), nr_fac = LP.Facturi.size();
	for (int i = 0; i < nr_loc; i++)
	{
		if (i == 0)
		{
			std::string sir = LP.completare("\t[]\t nume\t",MaxChrSize)+LP.completare("Vol_ApaR\t",MaxChrSize)+LP.completare("Sold\t",MaxChrSize);
			for (int j = 1; j < nr_fac; j++)
				sir += LP.completare(LP.Facturi[j].get_nume(), MaxChrSize) + '\t';
			std::cout << sir << "Total\n";
		}
		std::cout << i+1 << ": ";
		std::cout << LP.completare(LP.lista_locatari[i].get_nume(),MaxChrSize) << '\t';
		std::string alt_sir = std::to_string(std::ceil(LP.lista_locatari[i].get_v() * 100.0) / 100.0 );
		std::cout << LP.completare(alt_sir.erase(alt_sir.find_last_not_of('0')+2, std::string::npos),MaxChrSize) << '\t';
		for (int j = 0; j < nr_fac; j++)
			if (j == 0)
			{
				alt_sir = std::to_string(std::ceil(LP.lista_locatari[i].get_v() * LP.Facturi[0].get_cantitate() * 100.0) / 100.0);
				std::cout << LP.completare(alt_sir.erase(alt_sir.find_last_not_of('0') + 2, std::string::npos), MaxChrSize) << '\t';
			}
			else
			{
				alt_sir = std::to_string(std::ceil(LP.Facturi[j].get_numerar() / nr_loc*100)/100);
				std::cout << LP.completare(alt_sir.erase(alt_sir.find_last_not_of('0') + 2, std::string::npos), MaxChrSize)<< '\t';
			}
		std::cout << LP.Total[i] << '\n';
	}
	return os;
}

void lista_plata::operator>(std::string NumeLocatar) { //operator de modificare a informatiilor unei persoane 
	std::cin >> lista_locatari[cautareLocatar(NumeLocatar)];
}

void lista_plata::calcul_lista_plata()
{
	Total.clear();
	int nr_loc = lista_locatari.size(), nr_fac = Facturi.size();
	for (int i = 0; i < nr_loc; i++)
	{
		Total.push_back(0);
		for (int j = 0; j < nr_fac; j++)
		{
			if (j == 0) //(La apa rece)
				Total[i] += lista_locatari[i].get_v() * Facturi[j].get_cantitate();
			else
				Total[i] += Facturi[j].get_numerar() / nr_loc;
		}
	}
}

void lista_plata::stergereLocatar(std::string NumeLocatar)
{
	lista_locatari.erase(lista_locatari.begin() + cautareLocatar(NumeLocatar));
}

void lista_plata::stergereFactura(std::string NumeFactura)
{
	Facturi.erase(Facturi.begin() + cautareFactura(NumeFactura));
}