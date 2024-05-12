#pragma once
#ifndef PROGASOC
#define PROGASOC
#include <iostream>
#include "listaplata.h"

class ProgAsoc {
public:
	static void Run(lista_plata& LP);
	static void ColectiePersoane(std::vector<locatar> Loc, std::vector<angajat> Ang);
};
#endif