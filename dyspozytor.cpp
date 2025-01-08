#include "dyspozytor.h"
#include <iostream>   // std::cout, std::cin
#include <thread>     // std::this_thread::sleep_for
#include <chrono>     // std::chrono::milliseconds

Dyspozytor::Dyspozytor(Tasmociag& tasmociag,
    std::vector<Pracownik>& pracownicy,
    std::vector<Ciezarowka>& ciezarowki)
    : tasmociag_(tasmociag),
    pracownicy_(pracownicy),
    ciezarowki_(ciezarowki),
    pracaTrwa_(true),
    sygnal1_(false),
    sygnal2_(false)
{
}

Dyspozytor::~Dyspozytor()
{
}

void Dyspozytor::uruchomSymulacje()
{
    std::cout << "[INFO] Dyspozytor rozpoczyna zarz¹dzanie symulacj¹." << std::endl;

    // Przyk³adowa pêtla, która w ma³ym odstêpie czasu sprawdza, 
    // czy u¿ytkownik wpisa³ cokolwiek w konsoli:
    while (pracaTrwa_)
    {
        // Tu mo¿e byæ np. prosty mechanizm pobierania klawisza (sygna³ 1, sygna³ 2)
        // Dla przyk³adu, wciskasz '1' -> sygna³ 1, '2' -> sygna³ 2, 'q' -> koniec.

        if (std::cin.rdbuf()->in_avail() > 0)
        {
            char c;
            std::cin >> c;
            switch (c)
            {
            case '1':
                wydajSygnal1();
                break;
            case '2':
                wydajSygnal2();
                break;
            case 'q':
                // Mo¿esz uznaæ, ¿e 'q' to te¿ koniec symulacji
                std::cout << "[INFO] Dyspozytor otrzyma³ polecenie zakoñczenia (q)." << std::endl;
                wydajSygnal2();
                break;
            default:
                std::cout << "[INFO] Nieznany znak, u¿yj '1', '2' lub 'q'." << std::endl;
                break;
            }
        }

        // Mo¿na tu np. sprawdzaæ stan ciê¿arówek, pracowników,
        // i ewentualnie zakoñczyæ symulacjê, je¿eli wszyscy zakoñczyli pracê
        // lub je¿eli sygnal2_ jest ustawione i wszystkie ceg³y zosta³y rozwiezione itp.

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "[INFO] Dyspozytor zakoñczy³ zarz¹dzanie symulacj¹." << std::endl;
}

void Dyspozytor::wydajSygnal1()
{
    std::cout << "[INFO] Dyspozytor wydaje sygna³ 1 (odjazd niepe³ny)!" << std::endl;
    sygnal1_ = true;

    // W docelowym kodzie:
    // - mo¿na zlokalizowaæ ciê¿arówkê stoj¹c¹ przy taœmie
    // - wymusiæ, by natychmiast odjecha³a (np. przerwaæ pêtlê ³adowania)
    // sygnal1_ mo¿esz zaœ skasowaæ (np. sygnal1_ = false), gdy ciê¿arówka faktycznie odjedzie
}

void Dyspozytor::wydajSygnal2()
{
    std::cout << "[INFO] Dyspozytor wydaje sygna³ 2 (zakoñczyæ pracê)!" << std::endl;
    sygnal2_ = true;

    // Mo¿na np. poinformowaæ pracowników, by zamykali pêtle produkcyjne:
    // w praktyce mo¿na to zrobiæ przez globaln¹/flagi w klasie Pracownik,
    // albo przez semafory, sygna³y POSIX itd.

    // Nastêpnie, zale¿nie od logiki, mo¿na ustawiæ pracaTrwa_ = false,
    // jeœli chcesz natychmiast zakoñczyæ g³ówn¹ pêtlê Dyspozytora:
    // pracaTrwa_ = false;
}

bool Dyspozytor::czyPracaTrwa() const
{
    return pracaTrwa_;
}
