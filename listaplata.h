#pragma once
#ifndef LISTAPLATA
#define LISTAPLATA
#include <iostream>
#include <vector>
#include "factura.h"
#include "locatar.h"

#define nr_ap 2
#define nr_loc_max_ap 1 
#define nr_loc_max_sc (nr_ap*nr_loc_max_ap)

class lista_plata {
private:
	std::vector<locatar> lista_locatari;
	std::vector<factura> Facturi;
	std::vector<float> Total;

public:
	lista_plata(std::vector<locatar> listaloc = {}, std::vector<factura> Fact = {}) {
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
	friend std::istream& operator>>(std::istream& is, lista_plata& LP)
	{
		int length = LP.lista_locatari.size();
		if (nr_loc_max_sc - length > 0)
			std::cout << "Se vor citi " << nr_loc_max_sc - length << " locatari de la tastatura\n";
		for (int i = length; i < nr_loc_max_sc; i++)
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
	void calcul_lista_plata()
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
	std::string completare(std::string sir_initial, int nr_max_caractere)
	{
		std::string temp="";
		for (int j = sir_initial.size(); j < nr_max_caractere; j++)
			temp+= " ";
		return sir_initial+temp;
	}
	void afisare()
	{
		int MaxChrSize = 0;
		for (int i = 0; i < lista_locatari.size(); i++)
			if (MaxChrSize < lista_locatari[i].get_nume().size())
				MaxChrSize = lista_locatari[i].get_nume().size();
		for (int i = 0; i < Facturi.size(); i++)
			if (MaxChrSize < Facturi[i].get_nume().size())
				MaxChrSize = Facturi[i].get_nume().size();
		int nr_loc = lista_locatari.size(), nr_fac = Facturi.size();
		for (int i = 0; i < nr_loc; i++)
		{
			if (i == 0)
			{
				std::string sir = "[] nume\t Vol_ApaR\tSold\t";
				for (int j = 1; j < nr_fac; j++)
					sir += completare(Facturi[j].get_nume(), MaxChrSize) + '\t';
				std::cout << sir<<"Total\n";
			}
			std::cout << i << ": ";
			std::cout << completare(lista_locatari[i].get_nume(), MaxChrSize) << '\t';
			std::cout << lista_locatari[i].get_v() << '\t';
			for (int j = 0; j < nr_fac; j++)
				if(j==0)
					std::cout << lista_locatari[i].get_v() * Facturi[0].get_cantitate()<<'\t';
				else	
					std::cout << Facturi[j].get_numerar() / nr_loc << '\t';
			std::cout << Total[i]<<'\n';
		}
	}
};
#endif