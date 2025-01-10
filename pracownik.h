#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <string>

/**
 * Klasa reprezentuj�ca pracownika (P1, P2 lub P3),
 * kt�ry dok�ada ceg�y na ta�moci�g.
 */

class Pracownik
{
private:
    int id_;            ///< Unikalne ID pracownika (np. 1,2,3)
    int masaCegly_;     ///< Masa ceg�y, jak� wytwarza dany pracownik

public:
    
    Pracownik(int id, int masaCegly);

    
    ~Pracownik();

   
    void produkujCegly();

    
    int getMasaCegly() const;

    
    int getId() const;
};

#endif // PRACOWNIK_H
