#pragma once
#ifndef ANGAJAT
#define ANGAJAT
#include <iostream>
#include "persoana.h"

class angajat: public persoana {
private:
	std::string Titlu;
	int salariu;
public:
	angajat(std::string _nume = "", std::string _titlu="", int _salariu=0);
	friend std::istream& operator>>(std::istream& is, angajat& ang);
	friend std::ostream& operator<<(std::ostream& os, angajat& ang);
	float get_salariu();
	std::string get_titlu();
	void modificare();
};
#endif