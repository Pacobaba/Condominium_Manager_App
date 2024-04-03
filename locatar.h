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
	locatar(std::string _nume = "", int _nrAp = -1, float _v_apa = -1.f);
	locatar& operator=(const locatar& other);
	friend std::istream& operator>>(std::istream& is, locatar& loc);
	friend std::ostream& operator<<(std::ostream& os, locatar& loc);
	float get_v();
	std::string get_nume();
};
#endif