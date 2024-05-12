#pragma once
#ifndef LISTAPLATA
#define LISTAPLATA
#include <iostream>
#include <vector>
#include "factura.h"
#include "locatar.h"
#include "angajat.h"

class lista_plata{
private:
	static const int nr_ap;
	std::vector<locatar> lista_locatari;
	std::vector<angajat> lista_angajati;
	std::vector<factura> Facturi;
	std::vector<float> Total;
	int cautare(std::string DinCe, std::string Nume);
	std::string completare(std::string sir_initial, int nr_max_caractere);
	int listaString(std::string X);
public:
	lista_plata(std::vector<locatar> listaloc = {}, std::vector<angajat> listaang = {}, std::vector<factura> Fact = {});
	friend std::istream& operator>>(std::istream& is, lista_plata& LP);
	friend std::ostream& operator<<(std::ostream& os, lista_plata& LP);
	void afisareAngajati();
	void adaugareAngajat(angajat angTemp);
	void modificare(std::string Ce, std::string Nume);
	void calcul_lista_plata();
	void stergere(std::string DinCe, std::string Nume);
};
#endif