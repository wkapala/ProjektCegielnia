#include "ciezarowka.h"
#include <iostream>
#include <thread>    // std::this_thread::sleep_for
#include <chrono>    // std::chrono::seconds, etc.

Ciezarowka::Ciezarowka(int id, int ladownosc, int czasDostawy)
    : id_(id),
    ladownosc_(ladownosc),
    czasDostawy_(czasDostawy),
    aktualnaMasa_(0),
    wDrodze_(false)
{
}

Ciezarowka::~Ciezarowka()
{
}

void Ciezarowka::zaladuj(Tasmociag& tasmociag)
{
    // Przyk�adowe logi (docelowo mo�na usun��)
    std::cout << "[INFO] Ci�ar�wka " << id_
        << " rozpoczyna �adowanie. Aktualna masa: "
        << aktualnaMasa_ << std::endl;

    // Dop�ki ci�ar�wka nie jest pe�na i dop�ki s� ceg�y,
    // pobierz ceg�� z ta�moci�gu
    while (aktualnaMasa_ < ladownosc_)
    {
        int masaCegly = tasmociag.pobierzCegle();
        if (masaCegly < 0) {
            // Brak cegie� na ta�mie -> ko�czymy �adowanie
            std::cout << "[INFO] Brak cegie� na ta�mie. Masa w ci�ar�wce: "
                << aktualnaMasa_ << std::endl;
            break;
        }

        // Po pobraniu ceg�y
        aktualnaMasa_ += masaCegly;

        // Je�eli przekraczamy �adowno�� (teoretycznie nie powinno si� zdarzy�,
        // bo walidacja jest te� po stronie ta�moci�gu, ale na wszelki wypadek):
        if (aktualnaMasa_ > ladownosc_) {
            std::cerr << "[WARN] Przekroczono �adowno�� ci�ar�wki " << id_
                << "! ("
                << aktualnaMasa_ << " > " << ladownosc_ << ")\n";
            // mo�na zrobi� rollback lub jaka� inna obs�uga.
        }
    }

    std::cout << "[INFO] Ci�ar�wka " << id_
        << " zako�czy�a �adowanie. �adunek: "
        << aktualnaMasa_ << "/" << ladownosc_ << " jednostek." << std::endl;
}

void Ciezarowka::jedzWRozeznic()
{
    // Oznaczamy, �e ci�ar�wka jest w trasie
    wDrodze_ = true;
    std::cout << "[INFO] Ci�ar�wka " << id_
        << " wyrusza w tras� z �adunkiem " << aktualnaMasa_ << std::endl;

    // Symulujemy czas jazdy
    std::this_thread::sleep_for(std::chrono::seconds(czasDostawy_));

    // Po powrocie
    std::cout << "[INFO] Ci�ar�wka " << id_
        << " wr�ci�a i roz�adowa�a ceg�y (rozwo�enie zako�czone). " << std::endl;

    // Zdejmujemy ceg�y (roz�adowanie) - w praktyce masa staje si� 0
    aktualnaMasa_ = 0;
    wDrodze_ = false;
}

int Ciezarowka::getId() const
{
    return id_;
}

bool Ciezarowka::czyWDrodze() const
{
    return wDrodze_;
}

int Ciezarowka::getAktualnaMasa() const
{
    return aktualnaMasa_;
}
