#include "locatar.h"

locatar::locatar(std::string _nume, int _nrAp, float _v_apa)
{
	this->nume = _nume;
	this->nrApartament = _nrAp;
	this->v_aparece = _v_apa;
}

locatar& locatar::operator=(const locatar& other) {
	if (this != &other)
	{
		this->nume = other.nume;
		this->nrApartament = other.nrApartament;
		this->v_aparece = other.v_aparece;
	}
	return *this;
}

std::istream& operator>>(std::istream& is, locatar& loc)
{
	std::cout << "nume: ";
	is >> loc.nume;
	std::cout << "apa rece: ";
	is >> loc.v_aparece;
	return is;
}

std::ostream& operator<<(std::ostream& os, locatar& loc)
{
	os << loc.nrApartament << " " << loc.nume << " " << (loc.v_aparece == -1.f ? '\n' : loc.v_aparece);
	return os;
}

float locatar::get_v()
{
	return v_aparece;
}

std::string locatar::get_nume()
{
	return nume;
}