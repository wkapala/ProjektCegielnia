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
    // Przyk³adowe logi (docelowo mo¿na usun¹æ)
    std::cout << "[INFO] Ciê¿arówka " << id_
        << " rozpoczyna ³adowanie. Aktualna masa: "
        << aktualnaMasa_ << std::endl;

    // Dopóki ciê¿arówka nie jest pe³na i dopóki s¹ ceg³y,
    // pobierz ceg³ê z taœmoci¹gu
    while (aktualnaMasa_ < ladownosc_)
    {
        int masaCegly = tasmociag.pobierzCegle();
        if (masaCegly < 0) {
            // Brak cegie³ na taœmie -> koñczymy ³adowanie
            std::cout << "[INFO] Brak cegie³ na taœmie. Masa w ciê¿arówce: "
                << aktualnaMasa_ << std::endl;
            break;
        }

        // Po pobraniu ceg³y
        aktualnaMasa_ += masaCegly;

        // Je¿eli przekraczamy ³adownoœæ (teoretycznie nie powinno siê zdarzyæ,
        // bo walidacja jest te¿ po stronie taœmoci¹gu, ale na wszelki wypadek):
        if (aktualnaMasa_ > ladownosc_) {
            std::cerr << "[WARN] Przekroczono ³adownoœæ ciê¿arówki " << id_
                << "! ("
                << aktualnaMasa_ << " > " << ladownosc_ << ")\n";
            // mo¿na zrobiæ rollback lub jakaœ inna obs³uga.
        }
    }

    std::cout << "[INFO] Ciê¿arówka " << id_
        << " zakoñczy³a ³adowanie. £adunek: "
        << aktualnaMasa_ << "/" << ladownosc_ << " jednostek." << std::endl;
}

void Ciezarowka::jedzWRozeznic()
{
    // Oznaczamy, ¿e ciê¿arówka jest w trasie
    wDrodze_ = true;
    std::cout << "[INFO] Ciê¿arówka " << id_
        << " wyrusza w trasê z ³adunkiem " << aktualnaMasa_ << std::endl;

    // Symulujemy czas jazdy
    std::this_thread::sleep_for(std::chrono::seconds(czasDostawy_));

    // Po powrocie
    std::cout << "[INFO] Ciê¿arówka " << id_
        << " wróci³a i roz³adowa³a ceg³y (rozwo¿enie zakoñczone). " << std::endl;

    // Zdejmujemy ceg³y (roz³adowanie) - w praktyce masa staje siê 0
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
