#ifndef CIEZAROWKA_H
#define CIEZAROWKA_H

#include "tasmociag.h"

/**
 * Klasa reprezentuj�ca ci�ar�wk� odbieraj�c� ceg�y z ta�moci�gu.
 */
class Ciezarowka
{
private:
    int id_;                 ///< Unikalny numer ci�ar�wki (np. 1,2,...)
    int ladownosc_;          ///< Pojemno�� (C) � ile masy cegie� mo�e zmie�ci� si� w ci�ar�wce
    int czasDostawy_;        ///< Czas rozwo�enia cegie� (Ti) � po za�adowaniu ci�ar�wka wyje�d�a i wraca po tym czasie
    int aktualnaMasa_;       ///< Aktualnie za�adowana masa cegie�

    bool wDrodze_;           ///< Flaga, czy ci�ar�wka jest w trasie (rozwozi ceg�y) czy stoi przy ta�mie

public:
    /**
     * Konstruktor klasy Ciezarowka.
     * @param id            - unikalny numer ci�ar�wki
     * @param ladownosc     - maksymalna masa cegie� (C)
     * @param czasDostawy   - czas rozwo�enia cegie� (Ti)
     */
    Ciezarowka(int id, int ladownosc, int czasDostawy);

    /**
     * Destruktor (tu mo�e by� pusty).
     */
    ~Ciezarowka();

    /**
     * Metoda g��wna - pr�ba za�adowania cegie� z ta�moci�gu.
     * W p�tli pobiera ceg�y, a� osi�gnie �adowno�� lub brakuje cegie�.
     */
    void zaladuj(Tasmociag& tasmociag);

    /**
     * Symuluje wyjazd ci�ar�wki z ceg�ami i powr�t po pewnym czasie.
     * Mo�esz tu u�y� np. std::this_thread::sleep_for() (C++11) czy innego mechanizmu.
     */
    void jedzWRozeznic();

    /**
     * Zwraca ID ci�ar�wki.
     */
    int getId() const;

    /**
     * Zwraca, czy ci�ar�wka jest w trasie.
     */
    bool czyWDrodze() const;

    /**
     * Zwraca aktualnie za�adowan� mas� cegie�.
     */
    int getAktualnaMasa() const;
};

#endif // CIEZAROWKA_H
