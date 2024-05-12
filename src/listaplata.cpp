#include "..\include\listaplata.h"
#include <string>
const int lista_plata::nr_ap = 20;
const enum cod_string {
	locatari,
	facturi,
	angajati
};

std::string lista_plata::completare(std::string sir_initial, int nr_max_caractere)
{
	std::string temp = "";
	for (int j = sir_initial.size(); j < nr_max_caractere; j++)
		temp += " ";
	return temp+sir_initial;
}

lista_plata::lista_plata(std::vector<locatar> listaloc, std::vector<angajat> listaang, std::vector<factura> Fact) {
	for (int i = 0; i < listaloc.size(); i++)
		lista_locatari[i] = listaloc[i];
	for (int i = 0; i < listaang.size(); i++)
		lista_angajati[i] = listaang[i];
	if (Fact.size() > 0)
		for (int i = 0; i < Fact.size(); i++)
			Facturi[i] = Fact[i];
	else
	{
		Facturi.push_back(factura("ApaRece"));
		Facturi.push_back(factura("Curent "));
		Facturi.push_back(factura("Caldura"));
	}
}

std::istream& operator>>(std::istream& is, lista_plata& LP)
{
	int length = LP.lista_locatari.size();
	if (lista_plata::nr_ap - length > 0)
		std::cout << "Se vor citi " << lista_plata::nr_ap - length << " locatari de la tastatura\n";
	for (int i = length; i < lista_plata::nr_ap; i++)
	{
		locatar locatartemporar = locatar("", i);
		std::cout << "Al " << i + 1 << "-lea locatar: \n";
		is >> locatartemporar;
		LP.lista_locatari.push_back(locatartemporar);
	}
	int nrAng;
	std::cout << "Cati angajati vrei sa adaugi?";
	is >> nrAng;
	for (int i = 0; i < nrAng; i++)
	{
		angajat angajattemporar = angajat("", "", 0);
		std::cout << "Al " << i + 1 << "-lea angajat: \n";
		is >> angajattemporar;
		LP.lista_angajati.push_back(angajattemporar);
	}
	char ok;
	std::cout << "Exista alte facturi decat cele 4 standard? (Y/N)";
	is >> ok;
	length = LP.Facturi.size();
	int x = 0;
	if (ok == 'Y')
	{
		std::cout << "Cate alte facturi mai sunt? ";
		is >> x;
	}
	else
		if(ok!='N')
			throw std::runtime_error("Raspuns gresit");
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

void lista_plata::modificare(std::string Ce, std::string Nume) { 
	if (Ce == "locatar")
		lista_locatari[cautare(Ce+"i",Nume)].modificare();
	else if (Ce == "angajat")
		lista_angajati[cautare(Ce+"i",Nume)].modificare();
}
int lista_plata::listaString(std::string X){
	if (X == "locatari") return 0;
	if (X == "facturi") return 1;
	if (X == "angajati") return 2;
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

int lista_plata::cautare(std::string DinCe, std::string Nume) {
	switch (listaString(DinCe))
	{
	case locatari: {
		for (int i = 0; i < lista_locatari.size(); i++)
			if (lista_locatari[i].get_nume() == Nume)
				return i;
		break; }
	case facturi: {
		for (int i = 0; i < Facturi.size(); i++)
			if (Facturi[i].get_nume() == Nume)
				return i;
		break; }
	case angajati: {
		for (int i = 0; i < lista_angajati.size(); i++)
			if (lista_angajati[i].get_nume() == Nume)
				return i;
		break; }
	}
	throw std::runtime_error("Nu s-a gasit in " + DinCe);
	return -1;
}

void lista_plata::stergere(std::string DinCe, std::string Nume)
{
	int poz = cautare(DinCe, Nume);
	if(poz!=-1)
	switch (listaString(DinCe))
	{
	case locatari:{
		lista_locatari.erase(lista_locatari.begin() + poz);
		break;}
	case facturi: {
		Facturi.erase(Facturi.begin() + poz);
		break;}
	case angajati: {
		lista_angajati.erase(lista_angajati.begin() + poz);
		break;}
	}
}

void lista_plata::adaugareAngajat(angajat angTemp)
{
	lista_angajati.push_back(angTemp);
}

void lista_plata::afisareAngajati()
{
	if (lista_angajati.size() > 0) {
		std::cout << "Angajatii sunt:\n";
		for (int i = 0; i < lista_angajati.size(); i++)
			std::cout << lista_angajati[i] << "\n";
	}
	else
		std::cout << "Nu exista angajati!";
}