#include "..\include\angajat.h"

angajat::angajat(std::string _nume, std::string _titlu, int _salariu) : persoana(_nume)
{
	this->salariu = _salariu;
	this->Titlu = _titlu;
}

std::istream& operator>>(std::istream& is, angajat& ang)
{
	persoana& p = ang;
	is >> p;
	std::cout << "salariu: ";
	is >> ang.salariu;
	std::cout << "titlu: ";
	is >> ang.Titlu;
	return is;
}
float angajat::get_salariu()
{
	return salariu;
}
std::string angajat::get_titlu()
{
	return Titlu;
}
std::ostream& operator<<(std::ostream& os, angajat& ang)
{
	persoana& p = ang;
	os << p << ang.Titlu<<" "<<ang.salariu;
	return os;
}

void angajat::modificare()
{
	if (Vreau("numele angajatului")) {
		std::string _nume;
		bool Terminat = false;
		while (!Terminat) {
			std::cout << "Care e numele nou?\n";
			std::cin >> nume;
			if (_nume != nume) {
				nume = _nume;
				Terminat = true;
			}
			else std::cout << "Este deja acea informatie!\n";
		}
	}
	if (Vreau("numele titlului")) {
		std::string _titlu;
		bool Terminat = false;
		while (!Terminat) {
			std::cout << "Care e numele nou al titlului?\n";
			std::cin >> nume;
			if (_titlu != Titlu){
				Titlu=_titlu;
				Terminat = true;
			}
			else std::cout << "Este deja acea informatie!\n";
		}
	}
	if (Vreau("valoarea salariului")) {
		float _sal;
		bool Terminat = false;
		while (!Terminat) {
			std::cout << "Care e valoarea noua?\n";
			std::cin >> _sal;
			if (_sal != salariu) {
				salariu = _sal;
				Terminat = true;
			}
			else std::cout << "Este deja acea informatie!\n";
		}
	}
}