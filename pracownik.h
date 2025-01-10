#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <string>

/**
 * Klasa reprezentuj¹ca pracownika (P1, P2 lub P3),
 * który dok³ada ceg³y na taœmoci¹g.
 */

class Pracownik
{
private:
    int id_;            ///< Unikalne ID pracownika (np. 1,2,3)
    int masaCegly_;     ///< Masa ceg³y, jak¹ wytwarza dany pracownik

public:
    
    Pracownik(int id, int masaCegly);

    
    ~Pracownik();

   
    void produkujCegly();

    
    int getMasaCegly() const;

    
    int getId() const;
};

#endif // PRACOWNIK_H
