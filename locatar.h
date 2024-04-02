#pragma once
#ifndef LOCATAR
#define LOCATAR
#include <iostream>

class locatar
{
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
};


#endif