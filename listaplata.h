#pragma once
#ifndef LISTAPLATA
#define LISTAPLATA
#include <iostream>
#include <vector>
#include "factura.h"
#include "locatar.h"

#define nr_ap 20

class lista_plata {
private:
	std::vector<locatar> lista_locatari;
	std::vector<factura> Facturi;
	std::vector<float> Total;
	int cautareLocatar(std::string NumeLocatar);
	int cautareFactura(std::string NumeFactura);
	std::string completare(std::string sir_initial, int nr_max_caractere);
public:
	lista_plata(std::vector<locatar> listaloc = {}, std::vector<factura> Fact = {});
	friend std::istream& operator>>(std::istream& is, lista_plata& LP);
	friend std::ostream& operator<<(std::ostream& os, lista_plata& LP);
	void operator>(std::string NumeLocatar);
	void calcul_lista_plata();
	void stergereLocatar(std::string NumeLocatar);
	void stergereFactura(std::string NumeFactura);
};
#endif