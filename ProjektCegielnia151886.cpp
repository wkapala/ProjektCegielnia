#include <iostream>
#include <limits>
#include <functional> // dla std::function
#include <thread>
#include <vector>
#include "pracownik.h"
#include "ciezarowka.h"
#include "tasmociag.h"
#include "dyspozytor.h"

template <typename T>
T pobierzWartosc(const std::string& komunikat, std::function<bool(T)> walidator) {
    T wartosc;
    while (true) {
        std::cout << komunikat;
        std::cin >> wartosc;

        // Sprawdzenie, czy nie wyst¹pi³ b³¹d podczas wczytywania
        if (std::cin.fail()) {
            std::cin.clear(); // Czyœcimy flagi b³êdu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorujemy do koñca linii
            std::cout << "Niepoprawna wartosc. Sprobuj ponownie." << std::endl;
            continue;
        }

        // Czyœcimy strumieñ wejœcia
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Walidacja wartoœci
        if (walidator(wartosc)) {
            return wartosc;
        }
        else {
            std::cout << "Niepoprawna wartosc. Sprobuj ponownie." << std::endl;
        }
    }
}

int main() {
    // Pobieranie wartoœci od u¿ytkownika z walidacj¹
    int C = pobierzWartosc<int>(
        "Podaj ladownosc ciezarowki (C): ",
        [](int wartosc) { return wartosc > 0; }
    );

   /* if (C <= 0) {
        std::cout << "Blad: £adownosc ciezarowki musi byc wieksza od 0." << std::endl;
        return 1;f
     */

    int K = pobierzWartosc<int>(
        "Podaj maksymalna liczbe cegiel na tasmie (K) (W nastepnym kroku podasz laczna mase cegiel M, 3K musi byc mniejsze lub rowne M, aby nie przekroczyc udzwigu tasmy dla najciezszych cegiel.): ",
        [](int wartosc) { return wartosc > 0; }
    );

    int M = pobierzWartosc<int>(
        "Podaj maksymalna laczna mase cegiel na tasmie (M): ",
        [](int wartosc) { return wartosc > 0; }
    );

    if (3 * K > M) {
        std::cout << "Blad: 3K musi byc mniejsze lub rowne M, aby nie przekroczyc udzwigu tasmy dla najciezszych cegiel." << std::endl;
        return 1; // Zakoñcz program z kodem b³êdu
    }

    int N = pobierzWartosc<int>(
        "Podaj liczbe ciezarowek (N): ",
        [](int wartosc) { return wartosc > 0; }
    );

    int Ti = pobierzWartosc<int>(
        "Podaj czas powrotu ciezarowki (Ti) w sekundach: ",
        [](int wartosc) { return wartosc > 0; }
    );

    // Opcjonalnie dodatkowe parametry
    // ...

    
   

    // Kontynuacja programu...
}
