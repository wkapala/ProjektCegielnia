#include "pracownik.h"
#include "tasmociag.h"
#include <iostream>

Pracownik::Pracownik(int id, int masaCeg�y) : id(id), masaCeg�y(masaCeg�y) {}

void Pracownik::dodajCegle(Tasmociag& tasmociag)
{
	std::cout << "Pracownik " << id << " dodaje cegle o masie " << masaCeg�y << "jednostek." << std::endl;
}	
