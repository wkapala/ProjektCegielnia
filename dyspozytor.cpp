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
    std::cout << "[INFO] Dyspozytor rozpoczyna zarz�dzanie symulacj�." << std::endl;

    // Przyk�adowa p�tla, kt�ra w ma�ym odst�pie czasu sprawdza, 
    // czy u�ytkownik wpisa� cokolwiek w konsoli:
    while (pracaTrwa_)
    {
        // Tu mo�e by� np. prosty mechanizm pobierania klawisza (sygna� 1, sygna� 2)
        // Dla przyk�adu, wciskasz '1' -> sygna� 1, '2' -> sygna� 2, 'q' -> koniec.

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
                // Mo�esz uzna�, �e 'q' to te� koniec symulacji
                std::cout << "[INFO] Dyspozytor otrzyma� polecenie zako�czenia (q)." << std::endl;
                wydajSygnal2();
                break;
            default:
                std::cout << "[INFO] Nieznany znak, u�yj '1', '2' lub 'q'." << std::endl;
                break;
            }
        }

        // Mo�na tu np. sprawdza� stan ci�ar�wek, pracownik�w,
        // i ewentualnie zako�czy� symulacj�, je�eli wszyscy zako�czyli prac�
        // lub je�eli sygnal2_ jest ustawione i wszystkie ceg�y zosta�y rozwiezione itp.

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "[INFO] Dyspozytor zako�czy� zarz�dzanie symulacj�." << std::endl;
}

void Dyspozytor::wydajSygnal1()
{
    std::cout << "[INFO] Dyspozytor wydaje sygna� 1 (odjazd niepe�ny)!" << std::endl;
    sygnal1_ = true;

    // W docelowym kodzie:
    // - mo�na zlokalizowa� ci�ar�wk� stoj�c� przy ta�mie
    // - wymusi�, by natychmiast odjecha�a (np. przerwa� p�tl� �adowania)
    // sygnal1_ mo�esz za� skasowa� (np. sygnal1_ = false), gdy ci�ar�wka faktycznie odjedzie
}

void Dyspozytor::wydajSygnal2()
{
    std::cout << "[INFO] Dyspozytor wydaje sygna� 2 (zako�czy� prac�)!" << std::endl;
    sygnal2_ = true;

    // Mo�na np. poinformowa� pracownik�w, by zamykali p�tle produkcyjne:
    // w praktyce mo�na to zrobi� przez globaln�/flagi w klasie Pracownik,
    // albo przez semafory, sygna�y POSIX itd.

    // Nast�pnie, zale�nie od logiki, mo�na ustawi� pracaTrwa_ = false,
    // je�li chcesz natychmiast zako�czy� g��wn� p�tl� Dyspozytora:
    // pracaTrwa_ = false;
}

bool Dyspozytor::czyPracaTrwa() const
{
    return pracaTrwa_;
}
