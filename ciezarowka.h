#ifndef CIEZAROWKA_H
#define CIEZAROWKA_H

#include "tasmociag.h"

/**
 * Klasa reprezentuj¹ca ciê¿arówkê odbieraj¹c¹ ceg³y z taœmoci¹gu.
 */
class Ciezarowka
{
private:
    int id_;                 ///< Unikalny numer ciê¿arówki (np. 1,2,...)
    int ladownosc_;          ///< Pojemnoœæ (C) – ile masy cegie³ mo¿e zmieœciæ siê w ciê¿arówce
    int czasDostawy_;        ///< Czas rozwo¿enia cegie³ (Ti) – po za³adowaniu ciê¿arówka wyje¿d¿a i wraca po tym czasie
    int aktualnaMasa_;       ///< Aktualnie za³adowana masa cegie³

    bool wDrodze_;           ///< Flaga, czy ciê¿arówka jest w trasie (rozwozi ceg³y) czy stoi przy taœmie

public:
    /**
     * Konstruktor klasy Ciezarowka.
     * @param id            - unikalny numer ciê¿arówki
     * @param ladownosc     - maksymalna masa cegie³ (C)
     * @param czasDostawy   - czas rozwo¿enia cegie³ (Ti)
     */
    Ciezarowka(int id, int ladownosc, int czasDostawy);

    /**
     * Destruktor (tu mo¿e byæ pusty).
     */
    ~Ciezarowka();

    /**
     * Metoda g³ówna - próba za³adowania cegie³ z taœmoci¹gu.
     * W pêtli pobiera ceg³y, a¿ osi¹gnie ³adownoœæ lub brakuje cegie³.
     */
    void zaladuj(Tasmociag& tasmociag);

    /**
     * Symuluje wyjazd ciê¿arówki z ceg³ami i powrót po pewnym czasie.
     * Mo¿esz tu u¿yæ np. std::this_thread::sleep_for() (C++11) czy innego mechanizmu.
     */
    void jedzWRozeznic();

    /**
     * Zwraca ID ciê¿arówki.
     */
    int getId() const;

    /**
     * Zwraca, czy ciê¿arówka jest w trasie.
     */
    bool czyWDrodze() const;

    /**
     * Zwraca aktualnie za³adowan¹ masê cegie³.
     */
    int getAktualnaMasa() const;
};

#endif // CIEZAROWKA_H
