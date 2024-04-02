#pragma once
#ifndef FACTURA
#define FACTURA
#include <iostream>

class factura
{
private:
	std::string nume;
	float valoare;
	std::string cod_bon;
public:
	factura(std::string _nume = "", int val = -1, std::string bon="")
	{
		nume = _nume;
		valoare = val;
		cod_bon = bon;
	}
	factura& operator=(const factura& other_factura){
		if (this != &other_factura)
		{
			this->nume = other_factura.nume;
			this->valoare = other_factura.valoare;
			this->nume = other_factura.nume;
		}
		return *this;
	}
};


#endif