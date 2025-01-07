#include "pracownik.h"
#include "tasmociag.h"
#include <iostream>

Pracownik::Pracownik(int id, int masaCeg造) : id(id), masaCeg造(masaCeg造) {}

void Pracownik::dodajCegle(Tasmociag& tasmociag)
{
	std::cout << "Pracownik " << id << " dodaje cegle o masie " << masaCeg造 << "jednostek." << std::endl;
}	
