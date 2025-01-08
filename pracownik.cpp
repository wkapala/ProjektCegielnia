#include "pracownik.h"
#include <iostream>  

Pracownik::Pracownik(int id, int masaCegly)
    : id_(id), masaCegly_(masaCegly)
{
    // Mo¿na dodaæ inicjalizacjê innych zasobów,
    // np. tworzenie w¹tku, semaforów, itp.
}

Pracownik::~Pracownik()
{
    // Tu ewentualne zwalnianie zasobów (np. zamykanie w¹tku)
}

void Pracownik::produkujCegly()
{
    // Przyk³adowy testowy komunikat (mo¿esz usun¹æ w gotowym projekcie):
    std::cout << "[INFO] Pracownik " << id_
        << " produkuje ceg³y o masie " << masaCegly_ << std::endl;

    // Tutaj w przysz³oœci mo¿na zaimplementowaæ:
    // 1. Pêtlê produkcji cegie³ i przekazywania ich do taœmoci¹gu.
    // 2. Mechanizmy synchronizacji (np. semafory, w¹tki).
    // 3. Obs³ugê sygna³ów (np. przerwania od Dyspozytora).
}

int Pracownik::getMasaCegly() const
{
    return masaCegly_;
}

int Pracownik::getId() const
{
    return id_;
}
