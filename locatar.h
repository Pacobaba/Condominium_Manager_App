#pragma once
#ifndef LOCATAR
#define LOCATAR
#include <iostream>

class locatar{
private:
	std::string nume;
	int nrApartament;
	float v_aparece;
public:
	locatar(std::string _nume = "", int _nrAp = -1, float _v_apa = -1.f)
	{
		this->nume = _nume;
		this->nrApartament = _nrAp;
		this->v_aparece = _v_apa;
	}
	locatar& operator=(const locatar& other) {
		if (this != &other)
		{
			this->nume = other.nume;
			this->nrApartament = other.nrApartament;
			this->v_aparece = other.v_aparece;
		}
		return *this;
	}
	friend std::istream& operator>>(std::istream& is, locatar& loc)
	{
		std::cout << "nume: ";
		is >> loc.nume;
		if (loc.v_aparece == -1.f)
		{
			std::cout << "apa rece: ";
			is >> loc.v_aparece;
		}
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, locatar& loc)
	{
		os << loc.nrApartament << " " << loc.nume << " "<<(loc.v_aparece==-1.f?'\n':loc.v_aparece);
		return os;
	}
	float get_v()
	{
		return v_aparece;
	}
	std::string get_nume()
	{
		return nume;
	}
};
#endif