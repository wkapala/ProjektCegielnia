#include "pracownik.h"
#include <iostream>  

Pracownik::Pracownik(int id, int masaCegly)
    : id_(id), masaCegly_(masaCegly)
{
    // Mo�na doda� inicjalizacj� innych zasob�w,
    // np. tworzenie w�tku, semafor�w, itp.
}

Pracownik::~Pracownik()
{
    // Tu ewentualne zwalnianie zasob�w (np. zamykanie w�tku)
}

void Pracownik::produkujCegly()
{
    // Przyk�adowy testowy komunikat (mo�esz usun�� w gotowym projekcie):
    std::cout << "[INFO] Pracownik " << id_
        << " produkuje ceg�y o masie " << masaCegly_ << std::endl;

    // Tutaj w przysz�o�ci mo�na zaimplementowa�:
    // 1. P�tl� produkcji cegie� i przekazywania ich do ta�moci�gu.
    // 2. Mechanizmy synchronizacji (np. semafory, w�tki).
    // 3. Obs�ug� sygna��w (np. przerwania od Dyspozytora).
}

int Pracownik::getMasaCegly() const
{
    return masaCegly_;
}

int Pracownik::getId() const
{
    return id_;
}
