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

        // Sprawdzenie, czy nie wyst�pi� b��d podczas wczytywania
        if (std::cin.fail()) {
            std::cin.clear(); // Czy�cimy flagi b��du
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorujemy do ko�ca linii
            std::cout << "Niepoprawna wartosc. Sprobuj ponownie." << std::endl;
            continue;
        }

        // Czy�cimy strumie� wej�cia
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Walidacja warto�ci
        if (walidator(wartosc)) {
            return wartosc;
        }
        else {
            std::cout << "Niepoprawna wartosc. Sprobuj ponownie." << std::endl;
        }
    }
}

int main() {
    // Pobieranie warto�ci od u�ytkownika z walidacj�
    int C = pobierzWartosc<int>(
        "Podaj ladownosc ciezarowki (C): ",
        [](int wartosc) { return wartosc > 0; }
    );

   /* if (C <= 0) {
        std::cout << "Blad: �adownosc ciezarowki musi byc wieksza od 0." << std::endl;
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
        return 1; // Zako�cz program z kodem b��du
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
