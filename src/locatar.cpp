#include "..\include\locatar.h"

locatar::locatar (std::string _nume, int _nrAp, float _v_apa): persoana(_nume)
{
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
	else
		return *this;

}

std::istream& operator>>(std::istream& is, locatar& loc)
{
	persoana& p = loc;
	is >> p;
	std::cout << "apa rece: ";
	is >> loc.v_aparece;
	return is;
}

std::ostream& operator<<(std::ostream& os, locatar& loc) 
{
	persoana& p = loc;
	os << p << loc.nrApartament << " " << (loc.v_aparece == -1.f ? '\n' : loc.v_aparece);
	return os;
}

float locatar::get_v()
{
	return v_aparece;
}

void locatar::modificare()
{
	if (Vreau("numele locatarului")){
		std::string _nume;
		bool Terminat = false;
		while (!Terminat){
			std::cout << "Care e numele nou?\n";
			std::cin >> nume;
			if (_nume != nume){
				nume = _nume;
				Terminat = true;}
			else std::cout << "Este deja acea informatie!\n";
		}
	}
	if (Vreau("valoarea la apa rece a locatarului")) {
		float _v_apa;
		bool Terminat = false;
		while (!Terminat) {
			std::cout << "Care e valoarea noua?\n";
			std::cin >> _v_apa;
			if (_v_apa!=v_aparece) {
				v_aparece = _v_apa;
				Terminat = true;
			}
			else std::cout << "Este deja acea informatie!";
		}
	}
	if (Vreau("numarul apartamentului asociat locatarului")) {
		int _nr_ap;
		bool Terminat = false;
		while (!Terminat) {
			std::cout << "Care e numarul nou?\n";
			std::cin >> _nr_ap;
			if (_nr_ap!=nrApartament) {
				nrApartament = _nr_ap;
				Terminat = true;
			}
			else std::cout << "Este deja acea informatie!";
		}
	}
}