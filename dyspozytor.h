#ifndef DYSPOZYTOR_H
#define DYSPOZYTOR_H

#include <vector>
#include "pracownik.h"
#include "ciezarowka.h"
#include "tasmociag.h"

/**
 * Klasa reprezentuj¹ca Dyspozytora zarz¹dzaj¹cego ca³¹ symulacj¹.
 * Odpowiada za:
 * - wysy³anie sygna³ów (1 - odjazd niepe³ny, 2 - zakoñczenie pracy),
 * - monitorowanie stanu pracowników i ciê¿arówek,
 * - ewentualne inicjowanie/podtrzymywanie pêtli symulacji.
 */
class Dyspozytor
{
private:
    // Referencje / wskaŸniki do g³ównych elementów systemu
    Tasmociag& tasmociag_;
    std::vector<Pracownik>& pracownicy_;
    std::vector<Ciezarowka>& ciezarowki_;

    // Mo¿ena przechowywaæ flagi dot. stanu symulacji
    bool pracaTrwa_;   ///< True, jeœli produkcja i transport jeszcze trwaj¹
    bool sygnal1_;     ///< Flagowo odzwierciedliæ polecenie "odjazdu niepe³nego"
    bool sygnal2_;     ///< Flagowo odzwierciedliæ polecenie "zakoñczenia pracy"

public:
    /**
     * Konstruktor Dyspozytora.
     * @param tasmociag   - referencja na obiekt taœmoci¹gu
     * @param pracownicy  - referencja na wektor pracowników
     * @param ciezarowki  - referencja na wektor ciê¿arówek
     */
    Dyspozytor(Tasmociag& tasmociag,
        std::vector<Pracownik>& pracownicy,
        std::vector<Ciezarowka>& ciezarowki);

    /**
     * Destruktor.
     */
    ~Dyspozytor();

    /**
     * Funkcja g³ówna - pêtla symulacji (lub start zarz¹dzania) w uproszczonej formie.
     * Mo¿e w niej nas³uchiwaæ na input u¿ytkownika (klawiatura),
     * i na podstawie tego inputu wywo³ywaæ sygna³1(), sygna³2() itp.
     */
    void uruchomSymulacje();

    /**
     * Sygnalizuj ciê¿arówce, ¿e ma odjechaæ z niepe³nym ³adunkiem (Sygna³ 1).
     * W uproszczeniu: ustawia flagê, lub wywo³uje jak¹œ metodê w ciê¿arówce/ach.
     */
    void wydajSygnal1();

    /**
     * Sygnalizuj pracownikom, ¿e koñcz¹ pracê (Sygna³ 2).
     */
    void wydajSygnal2();

    /**
     * Zwraca true, jeœli praca wci¹¿ trwa.
     */
    bool czyPracaTrwa() const;
};

#endif // DYSPOZYTOR_H


