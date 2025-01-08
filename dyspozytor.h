#ifndef DYSPOZYTOR_H
#define DYSPOZYTOR_H

#include <vector>
#include "pracownik.h"
#include "ciezarowka.h"
#include "tasmociag.h"

/**
 * Klasa reprezentuj�ca Dyspozytora zarz�dzaj�cego ca�� symulacj�.
 * Odpowiada za:
 * - wysy�anie sygna��w (1 - odjazd niepe�ny, 2 - zako�czenie pracy),
 * - monitorowanie stanu pracownik�w i ci�ar�wek,
 * - ewentualne inicjowanie/podtrzymywanie p�tli symulacji.
 */
class Dyspozytor
{
private:
    // Referencje / wska�niki do g��wnych element�w systemu
    Tasmociag& tasmociag_;
    std::vector<Pracownik>& pracownicy_;
    std::vector<Ciezarowka>& ciezarowki_;

    // Mo�ena przechowywa� flagi dot. stanu symulacji
    bool pracaTrwa_;   ///< True, je�li produkcja i transport jeszcze trwaj�
    bool sygnal1_;     ///< Flagowo odzwierciedli� polecenie "odjazdu niepe�nego"
    bool sygnal2_;     ///< Flagowo odzwierciedli� polecenie "zako�czenia pracy"

public:
    /**
     * Konstruktor Dyspozytora.
     * @param tasmociag   - referencja na obiekt ta�moci�gu
     * @param pracownicy  - referencja na wektor pracownik�w
     * @param ciezarowki  - referencja na wektor ci�ar�wek
     */
    Dyspozytor(Tasmociag& tasmociag,
        std::vector<Pracownik>& pracownicy,
        std::vector<Ciezarowka>& ciezarowki);

    /**
     * Destruktor.
     */
    ~Dyspozytor();

    /**
     * Funkcja g��wna - p�tla symulacji (lub start zarz�dzania) w uproszczonej formie.
     * Mo�e w niej nas�uchiwa� na input u�ytkownika (klawiatura),
     * i na podstawie tego inputu wywo�ywa� sygna�1(), sygna�2() itp.
     */
    void uruchomSymulacje();

    /**
     * Sygnalizuj ci�ar�wce, �e ma odjecha� z niepe�nym �adunkiem (Sygna� 1).
     * W uproszczeniu: ustawia flag�, lub wywo�uje jak�� metod� w ci�ar�wce/ach.
     */
    void wydajSygnal1();

    /**
     * Sygnalizuj pracownikom, �e ko�cz� prac� (Sygna� 2).
     */
    void wydajSygnal2();

    /**
     * Zwraca true, je�li praca wci�� trwa.
     */
    bool czyPracaTrwa() const;
};

#endif // DYSPOZYTOR_H


