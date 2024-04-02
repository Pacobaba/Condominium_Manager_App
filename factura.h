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
	factura(std::string _nume = "", float val = -1.f, std::string bon="")
	{
		nume = _nume;
		valoare_numerar = valoare_cantitativa = val;
		cod_bon = bon;
	}
	factura& operator=(const factura& other_factura){
		if (this != &other_factura)
		{
			this->nume = other_factura.nume;
			this->valoare_numerar = other_factura.valoare_numerar;
			this->valoare_cantitativa = other_factura.valoare_cantitativa;
			this->nume = other_factura.nume;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const factura& f)
	{
		os << f.nume << " " << f.valoare_numerar <<" "<<f.valoare_cantitativa<< std::endl;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, factura& fac)
	{
		if (fac.nume.size() == 0)
		{
			std::cout << "nume: ";
			is >> fac.nume;
		}
		else
		{
			std::cout << "nume: " << fac.nume << std::endl;
		}
		std::cout << "valoare numerar: ";
		is >> fac.valoare_numerar;
		std::cout << "valoare cantitativa: ";
		is >> fac.valoare_cantitativa;
		return is;
	}
	float get_numerar()
	{
		return valoare_numerar;
	}
	float get_cantitate()
	{
		return valoare_cantitativa;
	}
	std::string get_nume()
	{
		return nume;
	}
};
#endif