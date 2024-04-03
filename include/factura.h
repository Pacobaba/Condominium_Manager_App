#pragma once
#ifndef FACTURA
#define FACTURA
#include <iostream>

class factura{
private:
	std::string nume;
	float valoare_numerar;
	float valoare_cantitativa;
	std::string cod_bon;
public:
	factura(std::string _nume = "", float val = -1.f, std::string bon = "");
	factura& operator=(const factura& other_factura);
	friend std::ostream& operator<<(std::ostream& os, const factura& f);
	friend std::istream& operator>>(std::istream& is, factura& fac);
	float get_numerar();
	float get_cantitate();
	std::string get_nume();
};
#endif