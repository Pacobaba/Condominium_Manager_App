#include "..\include\persoana.h"

persoana::persoana(std::string _nume)
{
	this->nume = _nume;
}

std::string persoana::get_nume()
{
	return nume;
}

std::istream& operator>>(std::istream& is, persoana& per)
{
	std::cout << "nume: ";
	is >> per.nume;
	return is;
}

std::ostream& operator<<(std::ostream& os, persoana& per)
{
	os << per.nume << " ";
	return os;
}

bool persoana::Vreau(std::string X)
{
	std::string raspuns;
	std::cout << "Vrei sa schimbi " << X << " ? (Y/N)\n";
	std::cin >> raspuns;
	if (raspuns == "Y")
		return true;
	else
		if (raspuns == "N")
			return false;
	throw std::runtime_error("Raspuns gresit");
}