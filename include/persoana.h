#pragma once
#ifndef PERSOANA
#define PERSOANA
#include <iostream>

class persoana {
protected:
	std::string nume;
	bool Vreau(std::string X);
public:
	persoana(std::string _nume = "");
	std::string get_nume();
	friend std::istream& operator>>(std::istream& is, persoana& per);
	friend std::ostream& operator<<(std::ostream& os, persoana& per);
	virtual void modificare() = 0;
};
#endif