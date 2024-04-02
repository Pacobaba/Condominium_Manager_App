#pragma once
#ifndef LISTAPLATA
#define LISTAPLATA
#include <iostream>
#include <vector>
#include "factura.h"
#include "locatar.h"

class lista_plata
{
private:
	std::vector<locatar> lista_locatari;
	std::vector<float> sold_apa;
	std::vector<factura> Facturi;
	
public:
	lista_plata(std::vector<locatar> listaloc, std::vector<float> sold_ap, std::vector<factura> Fact) {
		for (int i = 0; i < listaloc.size(); i++)
			lista_locatari[i]=listaloc[i];
		if (Fact.size()>0)
			for (int i = 0; i < Fact.size(); i++)
				Facturi[i] = Fact[i];
		else
			{
				Facturi[0] = factura("ApaRece");
				Facturi[1] = factura("Curent");
				Facturi[2] = factura("Caldura");
			}
		for (int i = 0; i < sold_ap.size(); i++)
			sold_apa[i] = sold_ap[i];
	}

};


#endif