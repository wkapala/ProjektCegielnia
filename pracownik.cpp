#include "pracownik.h"
#include "tasmociag.h"
#include <iostream>

Pracownik::Pracownik(int id, int masaCegly) : id(id), masaCegly(masaCegly) {}

void Pracownik::dodajCegle(Tasmociag& tasmociag)
{
	std::cout << "Pracownik " << id << " dodaje cegle o masie " << masaCegly << "jednostek." << std::endl;
}	
