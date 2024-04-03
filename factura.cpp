#include "factura.h"

factura::factura(std::string _nume, float val, std::string bon)
{
	nume = _nume;
	valoare_numerar = valoare_cantitativa = val;
	cod_bon = bon;
}

factura& factura::operator=(const factura& other_factura) {
	if (this != &other_factura)
	{
		this->nume = other_factura.nume;
		this->valoare_numerar = other_factura.valoare_numerar;
		this->valoare_cantitativa = other_factura.valoare_cantitativa;
		this->nume = other_factura.nume;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const factura& f)
{
	os << f.nume << " " << f.valoare_numerar << " " << f.valoare_cantitativa << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, factura& fac)
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

float factura::get_numerar()
{
	return valoare_numerar;
}

float factura::get_cantitate()
{
	return valoare_cantitativa;
}

std::string factura::get_nume()
{
	return nume;
}